<template>
  <v-app>
    <v-toolbar app>
      <v-toolbar-title class="headline text-uppercase">
        <router-link to="/">
          <span>FT</span>
          <span class="font-weight-light">_PASTEBIN</span>
        </router-link>
      </v-toolbar-title>
      <v-spacer></v-spacer>
    </v-toolbar>

    <notifications group="main" />
    <v-content>
      <v-slide-y-transition mode="out-in">
        <router-view></router-view>
      </v-slide-y-transition>
    </v-content>
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

export default {
  name: 'App',
  data () {
    return {
      //
    }
  }
}
</script>
