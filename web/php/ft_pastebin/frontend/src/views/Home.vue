<template>
  <div>
    <v-container grid-list-md>
        <v-layout row wrap>
          <template v-for="paste in pastes">
              <v-flex xs12 sm6 md3 >
                <v-card >
                  <v-card-title primary-title>
                      <h3 class="headline mb-0 title_custom">{{ paste.title }}</h3>
                  </v-card-title>
                  <v-card-text class="paste">
                   <div>{{ paste.text }}</div>
                  </v-card-text>

                  <v-card-actions>
                    <v-btn flat color="primary" :to="{ name: 'paste', params: { id: paste.id } }">Open</v-btn>
                    <v-spacer></v-spacer>
                  </v-card-actions>
                </v-card>
              </v-flex>
          </template>
        </v-layout>
        <infinite-loading @infinite="loadMore"></infinite-loading>
    </v-container>
    <v-btn
      slot="activator"
      color="green darken-2"
      dark
      fab
      right
      bottom
      fixed
      to="new"
    >
      <v-icon>add</v-icon>
    </v-btn>
  </div>
</template>

<style>
  .title_custom {
    text-overflow: ellipsis;
    white-space: nowrap;
    overflow: hidden;
  }
  .paste {
    height: 100px;
    overflow: hidden;
  }
</style>

<script>
  import InfiniteLoading from 'vue-infinite-loading';

  export default {
    components: {
      InfiniteLoading
    },
    data() {
      return {
        pastes: [],
        page: 0,
      }
    },
    methods: {
      loadMore($state) {
        const path = window.location.protocol + '//' + window.location.hostname + ':8081';
        fetch(`${path}/home/${this.page}`, {method: 'GET'})
        .then(response => response.json())
        .then((res) => {
            this.page++;
            if (!res.key && res.key !== 'stop')
            {
              res.forEach((v) => { 
                if (v.text && v.text.length > 150)
                  v.text = v.text.substring(0, 150) + '...';
                this.pastes.push(v)
              });
              $state.loaded();
            } else $state.complete();
        });
      }
    },
  }
</script>
