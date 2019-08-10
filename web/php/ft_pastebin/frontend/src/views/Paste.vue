<template>
    <v-container grid-list-md>
        <v-layout row wrap>
            <v-flex xs12>
                <v-subheader class="title">Paste {{ paste.title }}</v-subheader>
                <v-card>
                    <v-container
                    fluid
                    grid-list-md
                    >
                        <v-layout row wrap>
                            <v-flex xs12>
                                <pre><code ref="code" :class="codeClass"></code></pre>
                            </v-flex>
                        </v-layout>
                    </v-container>
                </v-card>
            </v-flex>
            <v-flex xs12 md8>
                <v-subheader class="title">Infos</v-subheader>
                <v-card>
                   <v-list two-line>

                    <v-list-tile @click="">
                        <v-list-tile-action>
                        <v-icon color="indigo">title</v-icon>
                        </v-list-tile-action>
                        <v-list-tile-content>
                        <v-list-tile-sub-title>Title</v-list-tile-sub-title>
                        <v-list-tile-title>{{ paste.title }}</v-list-tile-title>
                        </v-list-tile-content>
                    </v-list-tile>
                    <v-divider inset></v-divider>
                    <v-list-tile @click="">
                        <v-list-tile-action>
                        <v-icon color="indigo">face</v-icon>
                        </v-list-tile-action>
                        <v-list-tile-content>
                        <v-list-tile-sub-title>Author</v-list-tile-sub-title>
                        <v-list-tile-title>{{ paste.author }}</v-list-tile-title>
                        </v-list-tile-content>
                    </v-list-tile>
                    <v-divider inset></v-divider>
                    <v-list-tile @click="">
                        <v-list-tile-action>
                        <v-icon color="indigo">language</v-icon>
                        </v-list-tile-action>

                        <v-list-tile-content>
                        <v-list-tile-sub-title>Language</v-list-tile-sub-title>
                        <v-list-tile-title>{{ paste.language }}</v-list-tile-title>
                        </v-list-tile-content>
                    </v-list-tile>
                    <v-divider inset></v-divider>
                    <v-list-tile @click="">
                        <v-list-tile-action>
                        <v-icon color="indigo">date_range</v-icon>
                        </v-list-tile-action>

                        <v-list-tile-content>
                        <v-list-tile-sub-title>Date</v-list-tile-sub-title>
                        <v-list-tile-title>{{ paste.date }}</v-list-tile-title>
                        </v-list-tile-content>
                    </v-list-tile>
                    <v-list-tile @click="">
                        <v-list-tile-action>
                        <v-icon color="indigo">date_range</v-icon>
                        </v-list-tile-action>

                        <v-list-tile-content>
                        <v-list-tile-sub-title>Expiration</v-list-tile-sub-title>
                        <v-list-tile-title>{{ paste.expire }}</v-list-tile-title>
                        </v-list-tile-content>
                    </v-list-tile>
                    <v-divider inset></v-divider>
                    <v-list-tile @click="">
                        <v-list-tile-action>
                        <v-icon color="indigo">lock</v-icon>
                        </v-list-tile-action>

                        <v-list-tile-content>
                        <v-list-tile-sub-title>Status</v-list-tile-sub-title>
                        <v-list-tile-title v-html="status"></v-list-tile-title>
                        </v-list-tile-content>
                    </v-list-tile>
                    <v-divider inset></v-divider>
                    <v-list-tile @click="">
                        <v-list-tile-action>
                        <v-icon color="indigo">timer_off</v-icon>
                        </v-list-tile-action>

                        <v-list-tile-content>
                        <v-list-tile-sub-title>Last views count</v-list-tile-sub-title>
                        <v-list-tile-title>{{ paste.count }}</v-list-tile-title>
                        </v-list-tile-content>
                    </v-list-tile>
                    </v-list>
                </v-card>
            </v-flex>
            <v-flex xs12 md4>
                <v-subheader class="title">Share</v-subheader>
                <v-card>
                    <v-container>
                        <v-layout wrap row fill-height>
                            <v-flex xs3 offset-xs5>
                                <v-icon style="margin-top: 30px" large>share</v-icon>
                            </v-flex>
                            <v-flex xs10 offset-xs1>
                                <v-text-field
                                    :value="link"
                                    readonly
                                    ref="textLink"
                                    label="Link"
                                    type="text"
                                ></v-text-field>
                            </v-flex>
                            <v-flex xs10 offset-xs1>
                                <v-btn
                                    block
                                    color="primary"
                                    @click.stop="copy"
                                >COPY</v-btn>
                            </v-flex>
                        </v-layout>
                    </v-container>
                </v-card>
            </v-flex>
        </v-layout>
    </v-container>
</template>

<script>

export default {
    name: 'paste',
    props: [ 'id' ],
    data() {
        return {
            paste: {},
            parsed: '',
            codeClass: {
                'syntax-highlight': true
            }
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
        status() {
            return this.paste && this.paste.private == '0' ? 'Public' : 'Private'
        },
        link() {
            return `${window.location.protocol}//${window.location.host}/paste/${this.paste.id}`
        },
        
    },
    watch: {
        parsed(){
            this.highlightSyntax();
        }, 
    },
    methods: {
        highlightSyntax(){
            this.$refs.code.innerHTML = this.escapedQuery;
            hljs.highlightBlock(this.$refs.code);
        },
        copy() {
            const elem = this.$refs.textLink;
            elem.focus();
            document.execCommand('selectAll');
            document.execCommand("copy");
            this.$notify({ group: 'main', title: 'Success !', type: 'success', text: 'Copied!'})
        }
    },
    mounted() {
        const path = window.location.protocol + '//' + window.location.hostname + ':8081';
        fetch(`${path}/${this.id}`, { method: 'GET' })
        .then(response => response.json())
        .then((res) => {
            this.paste = res;
            this.parsed = res.text;
            this.codeClass = {};
            this.codeClass['syntax-highlight'] = true;
            this.codeClass[this.paste.language] = true;
            this.highlightSyntax();
        }).catch((res) => {
            this.$router.replace({ name: '404' });
        });
    }
}
</script>


<style>
     .syntax-highlight {
        color: white;
        width:100%;
        min-height: 500px;
        max-height: 1000px;
        background: #2b2b2b;
        overflow-y: auto;
    }
</style>

