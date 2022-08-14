Name- Ritik Upmanyu, Sahil Gupta
Id- 2019B3A70517P, 2019B3A710154P

To run this project we just need a browser as it is already deployed on heroku
All the backend is hosted on this link(base-address)
https://laundrymanage.herokuapp.com/



Now if you want to compile the source code and run locally on your machine then
you need to have node installed
Then open terminal/cmd
cd to the folder backend
and then run the command "npm start"

Which will host backend on localhost:3000
All the apis will be accessible from the same base address
Options available-
Adding User-
https://laundrymanage.herokuapp.com/adduser?name=raj&id=10021
Removing User-
https://laundrymanage.herokuapp.com/removeuser?id=10021
Updating Machines-
https://laundrymanage.herokuapp.com/updatemachines
Getting whole list of queries-
https://laundrymanage.herokuapp.com/getQueries
Getting Pending queries-
https://laundrymanage.herokuapp.com/getPendingQueries
Accepting a query-
https://laundrymanage.herokuapp.com/acceptQueries?quid=694
Machine available query by user-
https://laundrymanage.herokuapp.com/machineavailable?bid=1&num_clothes=12
https://laundrymanage.herokuapp.com/machineavailablebycity?bcity=Pilani&num_clothes=12
Getting list of all users-
https://laundrymanage.herokuapp.com/getallusers
Sending booking query-
https://laundrymanage.herokuapp.com/sendbookquery?uid=10021&num=2&bname=Delhibranch
Checking status of the query-
https://laundrymanage.herokuapp.com/checkstatusquery?uid=694
Retrieving clothes-
https://laundrymanage.herokuapp.com/retrive?quid=694&uid=10021
Adding clothes-
https://laundrymanage.herokuapp.com/add_clothes?uid=10021&type=socks&quid=694
Getting List of Machines-
https://laundrymanage.herokuapp.com/get_machines


In front end we have home page which has list of all the queries
each pending query has approve button attached to it
admin can also view the list of users, list of machines and list of pending queries

There is also an update machine button in the navigation bar which calls the procedure update machine whichupdates the status of all the machines and 
notifies the user to collect his/her clothes.

You can checkout the frontend at
http://laundrymanaging.herokuapp.com/machines

To run frontend locally, open another terminal/cmd
cd to frontend and then run npm start
frontend will be accessible at localhost:8080



