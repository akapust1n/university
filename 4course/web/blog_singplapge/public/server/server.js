const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/web')
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
        password: String
    });
    let User = mongoose.model('User', schema);
    return User;
}

function tokenUser() {
    const schema = mongoose.Schema({
        token: String,
    });
    let Token = mongoose.model('Token', schema);
    return Token;
}


module.exports.response = (req) => {
    let parts = req.url.split('/')
    let method = parts[parts.length - 1]
    switch (method) {
        case 'session':
            return _session(req)
        default:
            return _wrongMethod(req);

    }
}


function _session(req) {
    const userSchema = schemaUser();
    const userToken = tokenUser()
    // var User = new model({
    //     name: JSON.stringify(this._req).name,
    //     password: SON.stringify(this._req).password
    // });
    // if (!!!v.validate(JSON.stringify(req.body), schema))
    //     return "wrong json";
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
                if (err) return 403;
                return token1;
            });
        }

    });
    return "user_not_found";

}

function _wrongMethod(req) {
    return 402;
}