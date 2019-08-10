<template>
    <v-container fluid>
        <v-subheader class="title">Write a paste</v-subheader>
        <v-card>
            <v-container
            fluid
            grid-list-md
            >
                <v-layout row wrap>
                     <v-flex xs12 md6 style="max-height: 500px">
                        <textarea v-model="parsed" class="ft-text-input"></textarea>
                    </v-flex>
                    <v-flex xs12 md6 style="max-height: 500px" class="parent-yolo">
                        <pre><code ref="code" :class="codeClass"></code></pre>
                    </v-flex>
                </v-layout>
                <v-divider></v-divider>
                <v-layout row wrap>
                    <v-flex md6 sm6 xs12>
                        <v-text-field
                            v-model="form.author"
                            label="Auteur"
                        ></v-text-field>
                    </v-flex>
                    <v-flex md6 sm6 xs12>
                        <v-text-field
                            v-model="form.title"
                            label="Titre"
                        ></v-text-field>
                    </v-flex>
                     <v-flex md6 sm6 xs12>
                        <v-text-field
                            v-model="form.count"
                            label="Counter"
                        ></v-text-field>
                    </v-flex>
                    <v-flex md6 sm6 xs12>
                        <v-select
                            v-model="language"
                            :items="languages"
                            label="language"
                        ></v-select>
                    </v-flex>
                    <v-flex md6 sm6 xs12>
                        <v-checkbox
                            v-model="form.private"
                            primary
                            label="Private"
                        ></v-checkbox>
                    </v-flex>
                    <v-flex md6 sm6 xs12>
                       <v-menu
                            ref="menu"
                            :close-on-content-click="false"
                            v-model="menu"
                            :nudge-right="40"
                            :return-value.sync="form.date"
                            lazy
                            transition="scale-transition"
                            offset-y
                            full-width
                            min-width="290px"
                        >
                            <v-text-field
                            slot="activator"
                            v-model="form.date"
                            label="Picker in menu"
                            prepend-icon="event"
                            readonly
                            ></v-text-field>
                            <v-date-picker v-model="form.date" no-title scrollable>
                                <v-spacer></v-spacer>
                                <v-btn flat color="primary" @click="menu = false">Cancel</v-btn>
                                <v-btn flat color="primary" @click="$refs.menu.save(form.date)">OK</v-btn>
                            </v-date-picker>
                        </v-menu>
                    </v-flex>
                </v-layout>
                <v-layout>
                    <v-spacer></v-spacer>
                    <v-btn
                        color="primary"
                        @click.stop="submit"
                    >
                        Submit
                    </v-btn>
                </v-layout>
            </v-container>
        </v-card>
    </v-container>
</template>
<style>
textarea {
    width: 100%;
    height: 500px;
    max-height: 500px;
    padding: 0 20px;
    margin-bottom: 30px;
}

.ft-text-input code {
    height: 500px;
    max-height: 500px;
    overflow-y: auto;
}
</style>

<script>

export default {
    name: 'new',
    components: {
    },
    data() {
        const today = new Date();
        const date = new Date();
        date.setDate(today.getDate() + 1);

        return {
            menu: false,
            languages: ['nohighlight', 'html', ...hljs.listLanguages()],
            parsed: '',
            codeClass: {
                'syntax-highlight': true
            },
            language: 'nohighlight',
            form: {
                text: '',            
                date: date.toISOString().substr(0, 10),
                title: 'Unamed',
                author: '',
                private: false,
                count: 10,
            }
        }
    },
    watch: {
        parsed(){
            this.highlightSyntax();
        },
        language() {
            this.highlightSyntax();
        }
    },
    computed: {
        escapedQuery(){
            return this.parsed
                .replace(/&/g, "&amp;")
                .replace(/</g, "&lt;")
                .replace(/>/g, "&gt;")
                .replace(/"/g, "&quot;")
                .replace(/'/g, "&#039;");
        },
    },
    methods: {
        highlightSyntax(){
            this.$refs.code.innerHTML = this.escapedQuery;
            this.codeClass = {};
            this.codeClass['syntax-highlight'] = true;
            this.codeClass[this.language] = true;
            hljs.highlightBlock(this.$refs.code);
            
        },
        submit() {
            const form = this.form;
            form.private = form.private == true ? 1 : 0
            form.language = this.language;
            form.count = parseInt(form.count);
            form.text = this.parsed;
            const path = window.location.protocol + '//' + window.location.hostname + ':8081';
            var formData = new FormData();
            formData.append("data",  JSON.stringify(this.form));
            fetch(`${path}/`, {
                method: 'POST',
                body: formData
            }).then(response => response.json())
            .then(({ error, link: id }) => {
                if (error)
                {
                    this.$notify({ group: 'main', title: 'Error !', type: 'error', text: error})
                    return;
                }
                this.$router.push({ name: 'paste', params: { id } })
            });
        }
    },
    mounted(){
        this.highlightSyntax();
    },
}
</script>

<style>
    .syntax-highlight {
        color: white;
        width:100%;
        height: 500px;
        background: #2b2b2b;
        overflow-y: auto;
    }
</style>


