//*           my Webserver

const express = require('express');    //?   "import express"
const datastore = require('nedb');     //?   "import nedb"

const app = express();                          //! create an express application
app.listen(3001, () => console.log("Listening at 3001"));
app.use(express.static('public'));              // !show content from public dir only! static file (index.html)
app.use(express.json({ limit: '3mb' }));        //! for the server to process received data 
//! 3mb limit for JSON files, to not flood the server


//* Create a Database for the web server
const database = new datastore('ISS_DB.db');
database.loadDatabase();

//* GET: fetch data from database based on response
app.get('/api', (request, response) => {
    database.find({}, (error, queries) => {  //! find(EVERYTHING) {}-> empty object , if we want to find specific things we can change {} to what we want
        if (error) {                         //! basic error handling
            response.end();
            console.log(error);
            return;
        }
        response.json(queries);              //! send everything back from the database
    });
});

//* POST: receive data and console log it
app.post('/api', (request, response) => {  //! post(address, callback function to send a response back), i chose /api because this is an api for the client to send\receive data
    //! request holds the information about the client
    console.log('I got a request!');      //* the server shows that it did get a request
    const RequestData = request.body;     //? request: holds the data that is being sent about the client
    const timestamp = Date.now();
    RequestData.timestamp = timestamp;
    database.insert(RequestData);        //! push received data to the database + a time stamp
    response.json(RequestData);          //? to complete the request,  response: the server response for that client
});