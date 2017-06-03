<template>
  <div class= "container " id="app">
    <img src="./assets/willferrel.jpg">
    <div class="container" v-if="loggedIn" >
      <div class="loginlogout">
        <button v-on:click="loggedIn = false"> Logout </button>
      </div>
      <orderMenu :userKey="key"></orderMenu>
    </div>
    <div class="container loginlogout" v-else>
          <input type="text" v-model="username" placeholder="Username"><br/>
          <input type="text" v-model="password" placeholder="Password"><br/>
          <button v-on:click="login"> Login </button>
          <button v-on:click="register"> Register </button>
    </div>
  </div>
</template>

<script>

import OrderMenu from './components/OrderMenu'

export default {
  name: 'app',
  components: {
    OrderMenu
  },
  data() {
      return {
          loggedIn: false,
          username: "",
          password: "",
          key: ""
      }
  },
  methods:{
    register : function(){
      this.$http.get('http://localhost/Register/username='
                      + this.username + '&password=' + this.password)
          .then(function(response){
                  if (response.body.status == 'success'){
                    console.log(response.body.key);
                  }
                  else console.log(response.body.message);
          })
      this.username = this.password = "";
    },
    login : function(){
      this.$http.get('http://localhost/RecoverKey/username='
                     + this.username + '&password=' + this.password)
        .then(function(response){
                if (response.body.status == 'success'){
                  console.log(this.key = response.body.key);
                  this.loggedIn = true;
                }
                else console.log(response.body.message);
        })
      this.username = this.password = "";
    }
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: #2c3e50;
  margin: auto;
}
  .container{
    padding:15px;
  }

  .loginlogout{
    margin-bottom: 50px;
  }

  img{
    width: 300px;
  }
</style>
