<template>
   <v-flex xs12 sm5 md4>
        <v-card ref="form">
            <v-card-text>
                <h1 class="text-xs-center">Sign Up</h1>
                <v-text-field
                    label="Login"
                    v-model="login"
                ></v-text-field>
                
                <v-text-field
                    label="Password"
                    v-model="pass"
                    type="password"
                ></v-text-field>
            </v-card-text>
            <v-divider class="mt-5"></v-divider>
            <v-card-actions>
                <v-layout justify-end>
                    <v-btn class="primary" @click.stop="send">
                        Sign Up
                    </v-btn>
                </v-layout>
            </v-card-actions>
        </v-card>
    </v-flex>
</template>

<script>
export default {
    name: 'login',
    data() {
        return {
            login: null, 
            pass: null
        }
    },
    methods: {
        send() {
            const path = window.location.protocol + '//' + window.location.hostname + ':4243';
            const formData = new FormData();
            formData.append("user", this.login);
            formData.append("password", this.pass);
            fetch(`${path}/admin`, { method: 'POST',  credentials: 'include', body: formData })
            .then((req) => {
                if (req.ok) { 
                    this.$notify({ group: 'main', title: 'Success !', type: 'success', text: 'Connected!'})
                    this.$router.push({ name: 'home' });
                    return ;
                }
                this.$notify({ group: 'main', title: 'Error !', type: 'error', text: 'Invalid Username/Password!'})
            })
        }
    }
}
</script>
