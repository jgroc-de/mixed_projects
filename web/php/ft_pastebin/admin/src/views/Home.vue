<template>
  <div>
    <v-container grid-list-md>
        <v-layout row wrap>
          <v-flex xs12>
            <v-data-table
                  :headers="header"
                  :items="pastes"
                  :loading="loading"
                  hide-actions
                  class="elevation-1"
              >
                  <template slot="items" slot-scope="props">
                      <tr>
                          <td>{{ props.item.id }}</td>
                          <td>{{ props.item.title }}</td>
                          <td>{{ props.item.author }}</td>
                          <td>{{ props.item.language }}</td>
                          <td>{{ props.item.count }}</td>
                          <td>{{ props.item.date }}</td>
                          <td>{{ props.item.expire }}</td>
                          <td>{{ props.item.private == '0' ? 'Public' : 'Private'  }}</td>
                          <td class="text-xs-right">
                              <v-icon small class="mr-2" @click.stop="editItem(props.item)">edit</v-icon>
                              <v-icon small @click.stop="deleteItem(props.item)">delete</v-icon>
                          </td>
                      </tr>
                  </template>
              </v-data-table>
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
                        <v-text-field v-model="dialog.data.title" label="Title"></v-text-field>
                    </v-flex>
                    <v-flex xs12>
                        <v-text-field v-model="dialog.data.author" label="Author"></v-text-field>
                    </v-flex>
                    <v-flex xs12>
                        <v-textarea v-model="dialog.data.text" label="Text"></v-textarea>
                    </v-flex>
                    <v-flex xs12>
                        <v-text-field v-model="dialog.data.language" label="Language"></v-text-field>
                    </v-flex>
                    <v-flex xs12>
                        <v-text-field v-model="dialog.data.count" label="Count"></v-text-field>
                    </v-flex>
                    <v-flex xs12>
                        <v-text-field v-model="dialog.data.expire" label="Expire"></v-text-field>
                    </v-flex>
                     <v-flex xs12>
                        <v-text-field v-model="dialog.data.date" label="Date"></v-text-field>
                    </v-flex>
                    <v-flex xs12>
                        <v-checkbox v-model="dialog.data.private" label="Private"></v-checkbox>
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
    components: {
    },
    data() {
      return {
        header: [
          { text: 'ID', value: 'id' },
          { text: 'Title', value: 'title' },
          { text: 'Author', value: 'author' },
          { text: 'Language', value: 'language' },
          { text: 'Count', value: 'count' },
          { text: 'Date', value: 'date' },
          { text: 'Expire', value: 'expire' },
          { text: 'Private', value: 'private' },
          { text: 'Actions', value: 'name', align: 'right', sortable: false }
        ],
        pastes: [],
        loading: true,
        dialog: { value: false, data: {} }
      }
    },
    methods: {
      deleteItem({ id }) {
        if (!confirm("Are you sure ?"))
          return ;
        const path = window.location.protocol + '//' + window.location.hostname + ':4243';
        fetch(`${path}/admin/delete/${id}`, { method: 'GET', credentials: 'include' })
        .then(({ ok }) => {
          if (!ok) {
            this.$notify({ group: 'main', title: 'Error !', type: 'error', text: 'Unable to remove paste!'});
            return ;
          }
          this.pastes = this.pastes.filter(({ id: i }) => i !== id)
          this.$notify({ group: 'main', title: 'Success !', type: 'success', text: 'Paste removed!'});
        })
      },
      editItem(item) {
        this.dialog.value = true;
        this.dialog.data = {...item};
        this.dialog.data.private = item.private == '1';
      },
      update() {
        if (this.dialog.value == false)
          return ;
        const path = window.location.protocol + '//' + window.location.hostname + ':4243';
        const formData = new FormData();
        formData.append('data', JSON.stringify(this.dialog.data))
        fetch(`${path}/admin/update`, { method: 'POST', credentials: 'include', body: formData })
        .then((res) => {
            if (res.ok)
              return res;
            throw res;
        }).then(res => {
          this.$notify({ group: 'main', title: 'Success !', type: 'success', text: 'Paste edit!'})
          this.dialog.value = false;
          this.dialog.data = {};
          this.getPastes();
        })
        .catch(() =>  this.$notify({ group: 'main', title: 'Error !', type: 'error', text: 'Unable to edit paste!'}))
      },
      getPastes() {
        this.loading = true;
        const path = window.location.protocol + '//' + window.location.hostname + ':4243';
        fetch(`${path}/admin/getDB`, { method: 'GET', credentials: 'include' })
          .then(response => response.json())
          .then((pastes) => {
            this.pastes = pastes;
            this.loading = false;
          })
          .catch(() => false);
      }
    },
    mounted() {
      this.getPastes();
    }
  }
</script>
