'use strict';

import Router from "./modules/router.js"
import MainView from "./views/main.js"
import LoginView from "./views/login.js"
import PostView from "./views/post.js"
import CreateView from "./views/create.js"
import EditView from "./views/edit.js"

import Session from "./models/session"


window.onload = () => {
  let routerConfig = () => {
    (new Router)
    .addRoute('/login', LoginView)
      .addRoute('/post', PostView)
      .addRoute('/edit', EditView)
      .addRoute('/create', CreateView)
      .addRoute('/', MainView)
      .start();
  }

  if (!!localStorage.userinfo) {
    window.session = new Session();
    //   window.session.save(JSON.parse(localStorage.userinfo)).then(routerConfig);
    routerConfig();
  } else {
    window.session = new Session();
    routerConfig();
  }
}