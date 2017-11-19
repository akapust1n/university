module.exports.mongoose = mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/web')
const async = require('async');
const url = require('url');


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
const schemaPost = new mongoose.Schema({
    id: Number,
    title: String,
    text: String,
    date: {
        type: Date,
        default: Date.now
    },
    author: String
}, {
    collection: "Posts"
});
let PostModel = mongoose.model('Posts', schemaPost);


const schemaUser = mongoose.Schema({
    name: String,
    password: String,
}, {
    collection: "User"
});
let User = mongoose.model('User', schemaUser);


const schemaToken = mongoose.Schema({
    token: String,
}, {
    collection: "Token"
});
let Token = mongoose.model('Token', schemaToken);



module.exports.response = (async function (req) {
    let parts = req.url.split('?')[0].split('/')
    let method = parts[parts.length - 1]
    //console.log(method)
    switch (method) {
        case 'session':
            let temp = await _Wrapper(req, _session);
            return temp;
        case 'create':
            let temp1 = await _Wrapper(req, _create);
            return temp1;
        case 'posts':
            let temp2 = await _Wrapper(req, _posts);
            return temp2;
        case 'postById':
            let temp3 = await _Wrapper(req, _postById);
            return temp3;
        case 'edit':
            let temp4 = await _Wrapper(req, _edit);
            return temp4;

        default:
            return _wrongMethod(req);

    }
})

function _session(req) {
    return new Promise((resolve, reject) => {
        // const userSchema = schemaUser();
        // const userToken = tokenUser()
        const user = JSON.parse(JSON.stringify(req.body))
        //console.log(v.validate(JSON.parse(JSON.stringify(req.body)), schema));
        if (!v.validate(JSON.parse(JSON.stringify(req.body)), schema).valid)
            return "wrong json";
        User.count({
            name: user.name,
            password: user.password
        }, (err, count) => {
            console.log("count", count);
            if (count > 0) {
                //console.log("countinto", count);
                const token1 = Math.random().toString(36).substr(2);
                const newToken = new Token({
                    token: token1
                });

                newToken.save((err) => {
                    if (err) resolve("no such user");
                    else resolve(token1);;
                })


            } else {
                resolve("no such user");
            }
        });
    })
}

function _create(req) {
    return new Promise((resolve, reject) => {
        const post = JSON.parse(JSON.stringify(req.body))
        //("POST_", post)
        PostModel.findOne({}).sort('-id').exec((err, max) => {
            //console.log("INTO__", err, max.id)
            const newPost = new PostModel({
                id: max.id + 1,
                author: post.author,
                title: post.title,
                text: post.text,
            });

            newPost.save((err) => {
                if (err) resolve("posting error");
                else resolve("post created!");;
            })
        });
    })
}

function _posts(req) {
    return new Promise((resolve, reject) => {
        var url_parts = url.parse(req.url, true);
        var query = url_parts.query;
        const num = query.num
        const offset = query.offset
        //  console.log("num", num)
        PostModel.find({}).sort('-date').skip(offset).limit(num).exec((err, posts) => {
            if (err) resolve("cant get posts!")
            else resolve(posts)
        });
    })
}

function _postById(req) {
    return new Promise((resolve, reject) => {
        var url_parts = url.parse(req.url, true);
        var query = url_parts.query;
        const id = query.id
        PostModel.find({
            "id": id
        }).exec((err, post) => {
            if (err) resolve("cant get post!")
            else resolve(post)
        });
    })
}

function _edit(req) {
    return new Promise((resolve, reject) => {
        const post = JSON.parse(JSON.stringify(req.body))
        PostModel.findOne({}).sort('-id').exec((err, max) => {


            PostModel.find({
                "id": post.id
            }).remove((err) => {
                if (err) resolve("edit error");
            });
            const newPost = new PostModel({
                id: post.id,
                author: post.author,
                title: post.title,
                text: post.text,
            });
            newPost.save((err) => {
                if (err) resolve("edit error");
                else resolve("edit success!");;
            })
        });
    })
}

async function _Wrapper(req, func) {
    let x = await func(req);
    //console.log("wrapper_result__ ", x);
    return x;
}

function _wrongMethod(req) {
    return 402;
}