import fetch from "node-fetch";
import express from "express";
const app = express();
//https://laundrymanaging.herokuapp.com/
//setting view engine to ejs
app.set("view engine", "ejs");
app.use(express.static("views"));
//route for index page
app.get("/", async function (req, res) {

    var subheading = "All queries";
    const obj = await fetchQueries();

    res.render("index", {

        subheading: subheading,
        obj: obj

    });
});

function fetchQueries() {
    return fetch("https://laundrymanage.herokuapp.com/getQueries")
        .then(res => res.json())
}

function fetchPending() {
    return fetch("https://laundrymanage.herokuapp.com/getPendingQueries")
        .then(res => res.json())
}


function fetchUsers() {
    return fetch("https://laundrymanage.herokuapp.com/getallusers")
        .then(res => res.json())
}

function fetchMachines() {
    return fetch("https://laundrymanage.herokuapp.com/get_machines")
        .then(res => res.json())
}

//route for magic page
app.get("/users", async function (req, res) {
    const users = await fetchUsers();

    res.render("users", {
        users: users
    });
});

app.get("/machines", async function (req, res) {
    const machines = await fetchMachines();

    res.render("machines", {
        machines: machines
    });
});

app.get("/pending", async function (req, res) {
    const queries = await fetchPending();
    var subheading = "Pending queries";
    res.render("pending", {
        subheading: subheading,
        queries: queries
    });
});
const port = process.env.PORT || 8080
app.listen(port, function () {
    console.log("Server is running on port 8080 ");
});