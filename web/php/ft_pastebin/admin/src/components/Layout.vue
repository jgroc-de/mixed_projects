<template>
    <div>
        <v-navigation-drawer
            persistent
            v-model="drawer"
            enable-resize-watcher
            fixed
            clipped
            app
        >
        <v-list>
             <v-list-tile
                to="/"
            >
                <v-list-tile-action>
                    <v-icon>dashboard</v-icon>
                </v-list-tile-action>
                <v-list-tile-content>
                    <v-list-tile-title>Home</v-list-tile-title>
                </v-list-tile-content>
            </v-list-tile>
            <v-list-tile
                to="admins"
            >
                <v-list-tile-action>
                    <v-icon>face</v-icon>
                </v-list-tile-action>
                <v-list-tile-content>
                    <v-list-tile-title>Admins</v-list-tile-title>
                </v-list-tile-content>
            </v-list-tile>
        </v-list>
        </v-navigation-drawer>
        <v-toolbar app clipped-left>
        <v-toolbar-side-icon @click.stop="drawer = !drawer"></v-toolbar-side-icon>
        <v-toolbar-title class="headline text-uppercase">
        
            <router-link to="/">
            <span>FT</span>
            <span class="font-weight-light">_PASTEBIN - Admin</span>
            </router-link>
        </v-toolbar-title>
        <v-spacer></v-spacer>
        <v-menu :nudge-width="50">
            <v-toolbar-title slot="activator">
                <span>{{ login }}</span>
                <v-icon>arrow_drop_down</v-icon>
            </v-toolbar-title>

            <v-list>
                <v-list-tile>
                    <v-list-tile-title @click="logout">Logout</v-list-tile-title>
                </v-list-tile>
            </v-list>
            </v-menu>
        </v-toolbar>

        <v-content>
            <v-slide-y-transition mode="out-in">
                <router-view></router-view>
            </v-slide-y-transition>
        </v-content>
    </div>
</template>

<script>
export default {
    name: 'layout',
    data() {
        return {
            drawer: false
        }
    },
    computed: {
        login() {
            return window.localStorage.getItem('user');
        }
    },
    methods: {
        logout() {
            const path = window.location.protocol + '//' + window.location.hostname + ':4243';
            fetch(`${path}/admin/logout`, { method: 'GET', credentials: 'include' })
                .then(() => this.$router.push({ name: 'login' }));
        }
    }
}
</script>
