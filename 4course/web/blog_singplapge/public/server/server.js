const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/web')
var async = require('async');

const Validator = require('jsonschema').Validator;
const v = new Validator();
const schema = {
    "type": "object",
    "properties": {
        "name": {
            "type": "string"
        },
        "password": {
            "type": "string"
        }
    },
    "required": ["password", "name"]
};


function schemaUser() {
    const schema = mongoose.Schema({
        name: String,
        password: String,
    }, {
        collection: "User"
    });
    let User = mongoose.model('User', schema);
    return User;
}

function tokenUser() {
    const schema = mongoose.Schema({
        token: String,
    }, {
        collection: "Token"
    });
    let Token = mongoose.model('Token', schema);
    return Token;
}


module.exports.response = (async function (req) {
    let parts = req.url.split('/')
    let method = parts[parts.length - 1]
    let result
    switch (method) {
        case 'session':
            let temp = await _sessionWrapper(req);
            console.log("TTTTTT", temp);
            return temp;
        default:
            return _wrongMethod(req);

    }
})

function _session(req) {
    return new Promise((resolve, reject) => {
        const userSchema = schemaUser();
        const userToken = tokenUser()
        const user = JSON.parse(JSON.stringify(req.body))
        console.log(v.validate(JSON.parse(JSON.stringify(req.body)), schema));
        if (!v.validate(JSON.parse(JSON.stringify(req.body)), schema).valid)
            return "wrong json";
        userSchema.count({
            name: user.name,
            password: user.password
        }, (err, count) => {
            console.log("count", count);
            if (count > 0) {
                console.log("countinto", count);
                const token1 = Math.random().toString(36).substr(2);
                const newToken = new userToken({
                    token: token1
                });

                newToken.save((err) => {
                    if (err) resolve(403);
                    else resolve(token1);;
                    console.log("result2__", resolve)
                })


            };
        });
    })
}
async function _sessionWrapper(req) {
    let x = await _session(req);
    console.log("wrapper_result__ ", x);
    return x;
}




function _wrongMethod(req) {
    return 402;
}