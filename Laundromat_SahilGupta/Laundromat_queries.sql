create database laundromat;
use laundromat;

-- Create Tables

drop table if exists machine;
create table machine(
mid int(11) not null unique,
bid int (11) not null,
quid int (11) default null,
time_stamp DATETIME DEFAULT null,
primary key (mid, bid),
foreign key (quid) references query (quid)
);

drop table if exists laundry_bag;
create table laundry_bag(
quid int (11) not null,
uid int (11) not null,
type varchar(50) not null,
foreign key (quid) references query (quid),
foreign key (uid) references user (uid)
);

drop table if exists user;
create table user(
user_name varchar(50) not null,
uid int(11) not null,
pick_clothes bit default 0,
primary key (uid)
);

drop table if exists employee;
create table employee(
eid int NOT NULL,
name varchar(50) NOT NULL,
bid int NOT NULL,
PRIMARY KEY (eid),
FOREIGN KEY (bid) references branch(bid)
);

drop table if exists cloth;
create table cloth(
cid int NOT NULL,
uid int NOT NULL,
type varchar(30) NOT NULL,
status int NOT NULL,
PRIMARY KEY (cid),
FOREIGN KEY (uid) references user(uid) ON DELETE CASCADE
);

drop table if exists add_remove_user_query;
create table add_remove_user_query(
	uquid int not null AUTO_INCREMENT,
	uid int not null,
    user_name varchar(50),
    add_remove bit,
    time_stamp DATETIME DEFAULT CURRENT_TIMESTAMP,
    primary key(uquid)
);

drop table if exists booking_query;
create table booking_query(
	bquid int not null AUTO_INCREMENT,
	uid int not null,
	num int,
    bid int,
    time_stamp DATETIME DEFAULT CURRENT_TIMESTAMP,
    primary key(bquid),
    foreign key (uid) references user(uid),
    foreign key (bid) references branch(bid)
);

drop table if exists query;
create table query(
	quid int not null auto_increment,
    uid int,
    query_id int not null,
    status bit,
    time_stamp DATETIME DEFAULT CURRENT_TIMESTAMP,
    type varchar(50) not null,
    primary key(quid),
    foreign key(uid) references user(uid)
);

drop table if exists branch;
create table branch(
bid int (11) not null,
bname varchar(50) not null,
bcity varchar(50) not null,
primary key (bid)
);

-- Create Procedures

DELIMITER $$
 create procedure machine_Available(in bid1 int, in number_clothes int, out check1 bit)
 reads sql data
 deterministic
 sql security invoker
 BEGIN
    if (select count(*)*5/number_clothes from machine
	where bid = bid1 and quid is null)>=1
		then set check1 =1;
	else
		set check1=0;

	end if;
    end $$;
    delimiter ;

DELIMITER $$
 create procedure machine_Available_by_city(in city_name varchar(50), in number_clothes int, out check1 bit)
 reads sql data
 deterministic
 sql security invoker
 BEGIN
    if (select count(*)*5/number_clothes from machine
	where bid = (select bid from branch 
	where bcity = city_name) and quid is null)>=1
		then set check1 =1;
	else
		set check1=0;
	end if;
    end $$;
    delimiter ;

DELIMITER $$
	 create procedure register_user_query(in username varchar(50), in uid1 int, out sta bit)
	 reads sql data
	 deterministic
	 sql security invoker
	 BEGIN
		declare query_id int;
		insert into add_remove_user_query(uid, user_name,add_remove)
		value
		(uid1, username, 1);
		select last_insert_id() into query_id;
		insert into query
		(query_id, status, type) value
		(query_id, 0, "add_user");
		end $$;
		delimiter ;

DELIMITER $$
	 create procedure register_user(in quid1 int, out sta bit)
	 reads sql data
	 deterministic
	 sql security invoker
	 BEGIN
		declare uid1 int;
		declare uquid1 int;
		declare user_name1 varchar(50);
		select query_id into uquid1 from query 
		where quid=quid1;
		select uid, user_name into uid1, user_name1 from (select * from add_remove_user_query 
		where uquid=uquid1) a;
		if((select count(*) from user where uid=uid1)>0)
			then set sta =0;
			delete from add_remove_user_query 
			where uqid=uquid1;
			delete from query
			where quid=quid1;
		else
			insert into user
			values (uid1,user_name1);
			set sta =1;
			update query 
			set status=1 
			where quid=quid1;
			end if;
		end $$;
		delimiter ;
        
DELIMITER $$
	 create procedure deregister_user_query(in uid1 int)
	 reads sql data
	 deterministic
	 sql security invoker
	 BEGIN
		declare query_id int;
		declare username varchar(50);
		select user_name into username from user where uid=uid1;
		insert into add_remove_user_query(uid, user_name,add_remove)
		value
		(uid1, username, 0);
		select last_insert_id() into query_id;
		insert into query
		(query_id, status, type) value
		(query_id, 0, "remove_user");
		end $$;
		delimiter ;

DELIMITER $$
	 create procedure deregister_user(in quid1 int, out sta bit)
	 reads sql data
	 deterministic
	 sql security invoker
	 BEGIN
		declare uid1 int;
		declare uquid1 int;
		declare user_name1 varchar(50);
		select query_id into uquid1 from query 
		where quid=quid1;
		select uid,  user_name into uid1, user_name1 from (select * from add_remove_user_query 
		where uquid=uquid1) a;
		if((select count(*) from user where uid=uid1)>0)
			then set sta =1;
			delete from user where uid=uid1;
			update query 
			set status=1 
			where quid=quid1;
		else
			set sta =0;
			delete from add_remove_user_query 
			where uqid=uquid1;
			delete from query
			where quid=quid1;
			end if;
		end $$;
		delimiter ;

DELIMITER $$
	 create procedure send_book_query(in uid int (11), in num int(11), in branch varchar(50))
	 reads sql data
	 deterministic
	 sql security invoker
	 BEGIN
		declare bid1 int(11);
		declare query_id int(11);
		select bid into bid1 from branch where bname = branch;
		insert into booking_query(uid, num, bid) 
		value
		(uid, num, bid1);
		select last_insert_id() into query_id;
		insert into query (uid, query_id, status, type) value
		(uid, query_id, 0, "book");
		end $$;
		delimiter ;

Delimiter $$
	create procedure add_cloth(uid1 int(11), type1 varchar(50), quid1 int(11))
	reads sql data
	deterministic
	sql security invoker
	BEGIN
		declare check1 bit;
		insert into laundry_bag(uid, type, quid) value
		(uid1, type1, quid1);
	end $$;
	delimiter ;
    
Delimiter $$
	create procedure book(in quid1 int(11), out out1 bit)
	reads sql data
	deterministic
	sql security invoker
	BEGIN
		declare u int(11);
		declare b int(11);
		declare n int(11);
		declare branch int(11);
		select query_id into b from query where quid = quid1 and status=0;
		select uid into u from query where quid = quid1;
		select num into n from booking_query where bquid =b;
		select bid into branch from booking_query where bquid =b;
		call machine_Available(branch, n, @out);
		if b = null
			then set @out =0;
			end if;
		if (select @out) =0
			then set out1 =0;
		else begin
				set out1 =1;
				set n = n/5;
				if n = 0
					then set n =1;
				end if;
				update query
				set status =1 where quid = quid1;
				insert into cloth (uid, type, booking_id)
				select uid, type, quid from laundry_bag where quid = quid1 and uid = u;
				delete from laundry_bag where quid = quid1 and quid =quid1;
				update machine
				set quid = quid1, time_stamp = current_timestamp()
				where mid in (select mid from (select mid from
				machine where bid= branch and quid is null
				limit n)t);
			end;
		end if;
		end $$;
		delimiter ;

DELIMITER $$
	 create procedure update_machines()
	 reads sql data
	 deterministic
	 sql security invoker
	 BEGIN
		create table temp_done_machines as 
		select * from machine 
		where date_add((time_stamp), Interval 2 minute)<current_timestamp();
		update machine
		set quid=null,
		time_stamp=null
		where mid in (select mid from temp_done_machines);
		update cloth
		set status =1
		where booking_id in (select quid from temp_done_machines);
		update user
		set pick_clothes=1 
		where uid in (
		select uid from temp_done_machines natural join query);
		drop table temp_done_machines;
		end $$;
		delimiter ;

Delimiter $$
	create procedure retrieve_clothes(quid1 int(11), uid1 int(11))
	reads sql data
	deterministic
	sql security invoker
	BEGIN
		insert into laundry_bag (uid, type, quid)
		select uid, type, booking_id from cloth where booking_id = quid1 and status =1;
		delete from cloth where booking_id = quid1 and status =1;
		update user set pick_clothes = 0 where uid = uid1;
	end $$;
	delimiter ;

-- Insert values into tables

insert into user
values
(43799, "Vijay"),
(78654, "Satyam"),
(31298, "Max"),
(68941, "Irshad"),
(35481, "Rukhzar");

insert into machine (mid, bid, status)
values
(1, 1, 0),
(2, 1, 0),
(3, 1, 0),
(4, 1, 0),
(5, 2, 0),
(6, 2, 0),
(7, 2, 0),
(8, 2, 0);

insert into branch values
(1, "Pilanibranch", "Pilani"),
(2, "Delhibranch", "Delhi");

-- Programme begins!
-- Hello!

-- 0. for admin to get user list
    select * from user order by user_name;

-- 1. register user query
    
		call register_user_query("Vishal", 54626, @sta);	
        select * from add_remove_user_query;
        select * from query;
    
-- 2. for registering a user by admin
		-- status tells us if the query was valid (user id doesn't already exists in the table)
		-- this is just a helper procedure which requires quid as input which will be given by
		-- a general procedure to execute all queries in the query table
        
		call register_user(004,@sta);
        select @sta;
		select * from user;
		
-- 3. deregister user query
    
		call deregister_user_query(54626);
        select * from add_remove_user_query;
        select * from query where status =0;
			-- please remember the quid from here.
		
-- 4. for deregistering a user by admin
	-- status tells us if the query was valid (user id exists in the table)
	-- this is just a helper procedure which requires quid as input which will be given by
	-- a general procedure to execute all queries in the query table
		
		call deregister_user(004,@sta);
			-- please input the remembered quid here.
        select @sta;
        select * from user;
        
-- 5.  to send book query

		start transaction;
		lock tables branch read, booking_query write, query write;

		-- input user id, number of clothes, and branch name where user wants to send clothes to.
		call send_book_query(43799, 2, "Delhibranch");
			-- user can note down his query id to check its status in the future
		commit;
		unlock tables;
        
        select * from booking_query;
        select * from query where uid = 43799;
			-- please remember the quid from here.
        
-- 6. to add clothes
		-- there are two tables. Cloth and Laundry bag. Cloth represents those clothes that have been accepted
        -- for washing. Laundry bag refers to the clothes that still wait approval.
        -- user adds clothes to the laundry bag. If his/her query is approved, those clothes are moved to the cloth
        -- table and washing starts.
        -- after washing is done, those clothes are moved back from cloth to laundry bag which the user can
        -- retrieve.
        
        select * from laundry_bag where quid=604;
			-- please enter the remembered quid here and in all subsequent places where required.
        
        start transaction;
        lock tables query read, laundry_bag write, cloth read;

        call add_cloth(43799, "socks", 604);
        call add_cloth(43799, "t-shirt", 604);
        call add_cloth(43799, "t-shirtv2", 604);
        call add_cloth(43799, "t-shirt 3", 604);
        call add_cloth(43799, "pant", 604);
        call add_cloth(43799, "coat", 604);
        call add_cloth(43799, "pyjama", 604);
        call add_cloth(43799, "pyjama 2", 604);
        call add_cloth(43799, "jeans", 604);
        call add_cloth(43799, "jeans 2", 604);
        
        select * from laundry_bag where uid = 43799 and quid = 604;
        select * from cloth;
        commit;
        unlock tables;
        
-- 7. to approve book query where quid is known.

    start transaction;
    call book (604, @out);
	select @out;
    commit;
    
    select * from laundry_bag;
    select * from cloth;
    select * from query where quid = 604;
    select * from user;
    select * from machine;
    
-- 8. update machine
    -- this procedure should be called regularly by the admin everyday

		call update_machines();
        select * from machine;
        select * from cloth;
        select * from user where uid = 43799;

-- 9. Retrieve clothes
		-- after user gets notified that his/her clothes have been washed, he sends the retreive
        -- query with his quid and clothes are transferred from cloth table to user's laundry bag.
			call retrieve_clothes(604, 43799);
            select * from cloth;
            select * from laundry_bag;
        
-- Programme ends!
-- Thank you!

-- Dropping tables, procedures and database

-- drop table user;
-- drop table branch;
-- drop table employee;
-- drop table machine;
-- drop table laundry_bag;
-- drop table cloth;
-- drop table add_remove_user_query;
-- drop table booking_query;
-- drop table query;

-- drop procedure machine_Available;
-- drop procedure machine_Available_by_city;
-- drop procedure register_user_query;
-- drop procedure register_user;
-- drop procedure deregister_user_query;
-- drop procedure deregister_user;
-- drop procedure send_book_query;
-- drop procedure add_cloth;
-- drop procedure book;
-- drop procedure update_machines;
-- drop procedure retrieve_clothes;

-- drop database laundromat;