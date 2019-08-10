import Vue from 'vue'
import Router from 'vue-router'
import Home from './views/Home.vue'

Vue.use(Router)

export default new Router({
  mode: 'history',
  base: process.env.BASE_URL,
  routes: [
    {
      path: '/',
      name: 'home',
      component: Home
    },
    {
      path: '/paste/:id',
      name: 'paste',
      props: true,
      component: () => import('./views/Paste.vue')
    },
    {
      path: '/new',
      name: 'new',
      component: () => import('./views/New.vue')
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
