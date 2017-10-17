var express = require('express'),
  router = express.Router(),
  mongoose = require('mongoose'),
  Article = mongoose.model('Article');

module.exports = (app) => {
  app.use('/', router);
};

const posts = [{
    id: 1,
    author: 'John',
    title: 'Templating with EJS',
    body: 'Blog post number 1'
  },
  {
    id: 2,
    author: 'Drake',
    title: 'Express: Starting from the Bottom',
    body: 'Blog post number 2'
  },
  {
    id: 3,
    author: 'Emma',
    title: 'Streams',
    body: 'Blog post number 3'
  },
  {
    id: 4,
    author: 'Cody',
    title: 'Events',
    body: 'Blog post number 4'
  }
]

router.get('/', function (req, res, next) {
  // Article.find(function (err, articles) {
  //   if (err) return next(err);
  //   res.render('index', {
  //     title: 'Generator-Express MVC',
  //     articles: articles
  //   });
  // });
  res.render('home', {
    topPost: posts[0],
    posts: posts.slice(1, posts.length)
  })

});

// blog post
router.get('/post/:id', (req, res) => {
  // find the post in the `posts` array
  const post = posts.filter((post) => {
    return post.id == req.params.id
  })[0]

  // render the `post.ejs` template with the post content
  res.render('post', {
    author: post.author,
    title: post.title,
    body: post.body
  })
})

router.get('/createblog', (req, res) => {

  res.render('createBlog', {})
})

router.get('/login', (req, res) => {

  res.render('login', {})
})

router.post('/login', (req, res) => {
  console.log("login post!")

  res.render('home', {
    topPost: posts[0],
    posts: posts.slice(1, posts.length)
  })
})
router.post('/createblog', (req, res) => {
  console.log("createblog post!")
  res.render('home', {
    topPost: posts[0],
    posts: posts.slice(1, posts.length)
  })
})
