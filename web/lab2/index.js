let fs = require('fs');
let http = require('http');
//let bodyParser = require('body-parser');
let path = require('path');
let express = require('express'); // Get the module
let app = express();
let bodyParser = require('body-parser');

app.use(bodyParser.json());
app.use(express.static('static'));

app.get('/', function (req, res) {
    res.sendFile(__dirname + '/static/html/hack.txt');
});

app.get('/hack', function (req, res) {
    res.sendFile(__dirname + '/static/html/index.html');
});
app.get('/hack2', function (req, res) {
    fs.readFile(__dirname + '/static/html/hack.txt', 'utf8', function (err, data) {
        if (err) {

            console.log('Could not find or open file for reading\n');
        } else {
            res.writeHead(200, {
                'Content-Type':

                    'text/html'
            });

            res.end(data);
        }
    })
});

app.post('/save', function (req, res) {
    let pathtofile = __dirname + '/static/temp';

    fs.writeFile(pathtofile, JSON.stringify(req.body), (err) => {
        console.log(err)
        if (err) console.log("error write to file")
    });

    res.send("file created");
});

app.set('port', (process.env.PORT || 8081));

app.listen(app.get('port'), function () {
    console.log('server on ' + app.get('port'));
});