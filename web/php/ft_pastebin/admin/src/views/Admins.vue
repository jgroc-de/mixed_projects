<template>
  <div>
    <v-container grid-list-md>
        <v-layout row wrap>
          <v-flex xs12>
            <v-subheader class="title">Admins</v-subheader>
            <v-data-table
                  :headers="header"
                  :items="admins"
                  :loading="loading"
                  hide-actions
                  class="elevation-1"
              >
                  <template slot="items" slot-scope="props">
                      <tr>
                          <td>{{ props.item.id }}</td>
                          <td>{{ props.item.login }}</td>
                          <td>{{ props.item.date }}</td>
                          <td class="text-xs-right">
                              <v-icon small class="mr-2" @click.stop="edit(props.item)">edit</v-icon>
                              <v-icon small @click.stop="del(props.item)">delete</v-icon>
                          </td>
                      </tr>
                  </template>
              </v-data-table>
            </v-flex>
            <v-flex xs12>
                <v-subheader class="title">Add Admin</v-subheader>
                <v-card>
                    <v-container fluid>
                        <v-layout row wrap>
                            <v-flex xs12 md6>
                                <v-text-field v-model="login" label="Login"></v-text-field>
                            </v-flex>
                            <v-flex xs12 md6>
                                <v-text-field v-model="pass" type="password" label="Password"></v-text-field>
                            </v-flex>
                        </v-layout>
                        <v-btn color="primary" @click.stop="add">ADD</v-btn>
                    </v-container>
                </v-card>
            </v-flex>
        </v-layout>
    </v-container>
    <v-dialog v-model="dialog.value" max-width="500px">
        <v-card>
            <v-card-title>
                <span class="headline">Edit</span>
            </v-card-title>

            <v-card-text>
                <v-container grid-list-md>
                <v-layout wrap row>
                    <v-flex xs12>
                        <v-text-field v-model="dialog.data.login" label="Login"></v-text-field>
                    </v-flex>
                    <v-flex xs12>
                        <v-text-field v-model="dialog.data.pass" type="password" label="Password"></v-text-field>
                    </v-flex>
                </v-layout>
                </v-container>
            </v-card-text>

            <v-card-actions>
                <v-spacer></v-spacer>
                <v-btn color="blue" flat @click.native="dialog.value = false">Cancel</v-btn>
                <v-btn color="blue" @click.native="update">Save</v-btn>
            </v-card-actions>
        </v-card>
    </v-dialog>
  </div>
</template>

<script>

  export default {
    name: 'admins',
    data() {
      return {
        login: '',
        pass: '',
        header: [
          { text: 'ID', value: 'id' },
          { text: 'Login', value: 'login' },
          { text: 'Date', value: 'date' },
          { text: 'Actions', value: 'name', align: 'right', sortable: false }
        ],
        admins: [],
        loading: true,
        dialog: { value: false, data: {} }
      }
    },
    methods: {
        add() {
            const formData = new FormData();
            formData.append('login', this.login)
            formData.append('pass', this.pass)
            const path = window.location.protocol + '//' + window.location.hostname + ':4243';
            fetch(`${path}/admin/addAdmin`, { method: 'POST', credentials: 'include', body: formData })
            .then((res) => {
                if (res.ok)
                    return res;
                throw res;
            }).then(res => {
                this.$notify({ group: 'main', title: 'Success !', type: 'success', text: 'Admin added!'})
                this.login = '';
                this.pass = '';
                this.getAdmins();
            })
            .catch(() =>  this.$notify({ group: 'main', title: 'Error !', type: 'error', text: 'Unable to add admin!'}))
        },
        del({ id }) {
            if (!confirm("Are you sure ?"))
                return ;
            const path = window.location.protocol + '//' + window.location.hostname + ':4243';
            fetch(`${path}/admin/delAdmin/${id}`, { method: 'GET', credentials: 'include' })
            .then(({ ok }) => {
                if (!ok) {
                    this.$notify({ group: 'main', title: 'Error !', type: 'error', text: 'Unable to remove admin!'});
                    return ;
                }
                this.admins = this.admins.filter(({ id: i }) => i !== id)
                this.$notify({ group: 'main', title: 'Success !', type: 'success', text: 'Admin removed!'});
            })
        },
        edit(item) {
            this.dialog.value = true;
            this.dialog.data = {...item};
        },
        update() {
            if (this.dialog.value == false)
                return ;
            const path = window.location.protocol + '//' + window.location.hostname + ':4243';
            const formData = new FormData();
            formData.append('data', JSON.stringify(this.dialog.data))
            fetch(`${path}/admin/updateAdmin`, { method: 'POST', credentials: 'include', body: formData })
                .then((res) => {
                    if (res.ok)
                        return res;
                    throw res;
                }).then(res => {
                    this.$notify({ group: 'main', title: 'Success !', type: 'success', text: 'Admin edited!'})
                    this.dialog.value = false;
                    this.dialog.data = {};
                })
                .catch(() =>  this.$notify({ group: 'main', title: 'Error !', type: 'error', text: 'Unable to edit admin!'}))
        },
        getAdmins() {
            this.loading = true;
            const path = window.location.protocol + '//' + window.location.hostname + ':4243';
            fetch(`${path}/admin/admins`, { method: 'GET', credentials: 'include' })
                .then(response => response.json())
                .then((admins) => {
                    this.admins = admins;
                    this.loading = false;
                })
                .catch(() => false);
        }
    },
    mounted() {
      this.getAdmins();
    }
  }
</script>
