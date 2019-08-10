<template>
  <v-app>
    <notifications group="main" />
    <v-slide-y-transition mode="out-in">
      <layout v-if="!isAuth"></layout>
      <auth-layout v-else></auth-layout>
    </v-slide-y-transition>
  </v-app>
</template>

<style>
  .slide-fade-enter-active {
    transition: all .3s ease;
  }
  .slide-fade-leave-active {
    transition: all .8s cubic-bezier(1.0, 0.5, 0.8, 1.0);
  }
  .slide-fade-enter, .slide-fade-leave-to {
    transform: translateX(10px);
    opacity: 0;
  }
  .router-link-active {
    text-decoration: none;
    color: black;
  }
</style>

<script>
import Layout from '@/components/Layout'
import AuthLayout from '@/components/AuthLayout'

export default {
  name: 'App',
  data () {
    return {
      //
    }
  },
  components: {
    AuthLayout,
    Layout
  },
  computed: {
    isAuth() {
      return this.$route.path.startsWith('/auth/')
    }
  }
}
</script>
