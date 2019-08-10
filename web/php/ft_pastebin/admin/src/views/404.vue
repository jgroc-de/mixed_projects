<template>
  <v-container>
    <v-layout align-center justify-center row fill-height>
      <v-flex sm8 xs12>
        <div class="not-found">
          <v-card>
            <img src="https://cdn.discordapp.com/attachments/349974957998080001/355086450699534336/unknown.png">
            <v-container fill-height fluid>
              <v-layout fill-height>
                <v-flex xs12 align-end flexbox>
                  <h1 class="err">404</h1>
                  <h2 class="main-message">Not found</h2>
                  <h3 class="sub-message">That's your fault. Baka.</h3>
                </v-flex>
              </v-layout>
            </v-container>
          </v-card>
        </div>
      </v-flex>
    </v-layout>
  </v-container>
</template>

<script>
export default {
    
}
</script>

<style>
    .not-found img {
      width: 100%;
      height: auto;
    }
    
    .not-found iframe {
      width: 100%;
      height: 400px;
    }
    .not-found .err {
      font-size: 24px;
    }
    
    .not-found  .main-message {
      font-size: 20px;
    }
    .not-found .sub-message {
      font-size: 14px;
    }
</style>
