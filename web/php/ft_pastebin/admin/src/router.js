import Vue from 'vue'
import Router from 'vue-router'
import Home from './views/Home.vue'

Vue.use(Router)

const router = new Router({
  mode: 'history',
  base: process.env.BASE_URL,
  routes: [
    {
      path: '/',
      name: 'home',
      component: Home
    },
    {
      path: '/admins',
      name: 'admins',
      component: () => import ('@/views/Admins')
    },
    {
      path: '/auth/login',
      name: 'login',
      component: () => import ('@/views/Login')
    },
    {
      name: "404",
      path: "/404",
      component: () => import("./views/404.vue")
    },
    {
      path: '*',
      redirect: '/404'
    }
  ]
})

async function isLoggedIn() {
  const path = window.location.protocol + '//' + window.location.hostname + ':4243';
  return fetch(`${path}/logged`, { method: 'GET', credentials: 'include' })
        .then(response => response.json())
        .then(({ logged, login }) => {
          window.localStorage.setItem('user', login)
          return logged
        })
        .catch(() => false);
}

router.beforeEach(async (to, from, next) => {
  const needAuth = !to.path.startsWith('/auth/');
  if (needAuth && !(await isLoggedIn())) {
    next({ name: 'login' })
  } else {
    if (to.path.startsWith('/auth/') && await isLoggedIn())
      next({ name: 'home' })
    else next()
  }
})

export default router;
