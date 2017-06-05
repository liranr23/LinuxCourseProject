<template>
  <div class= "container" id="app">
    <div class="row">
        <div class="container-fluid" v-if="loggedIn" >
            <div class="row">
              <div class="col-1 offset-11">
                <button id="logoutButton" v-on:click="loggedIn = false"> Logout </button>
              </div>
            </div>
            <div class="row">
              <img class="logo col-4 offset-5" src="./assets/002-3d-glasses.svg">
            </div>
            <div class="row">
              <orderMenu :userKey="key"></orderMenu>
            </div>
        </div>
        <div class="col-6 offset-5 loginlogout" v-else>
          <div class= "row">
              <img class="logo" src="./assets/002-3d-glasses.svg">
          </div>
          <div class="row">
              <input type="text"  v-on:keydown="errorMessage=successMessage=''" v-model="username" placeholder="Username">
          </div>
          <div class="row">
              <input type="text" v-on:keydown="errorMessage=successMessage=''" v-model="password" placeholder="Password">
          </div>
          <div class="row">
              <button id="loginButton" v-on:click="login">Login</button>
              <button id="registerButton" v-on:click="register">Register</button>
          </div>
          <div class="row">
              <p class="error" >{{errorMessage}}</p>
              <p class="success"> {{successMessage}}</p>
          </div>
        </div>
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
          key: "",
          errorMessage: "",
          successMessage: "",
          url: "http://146.185.177.17"
      }
  },
  methods:{
    register : function(){
      this.$http.get(this.url + '/Register/username='
                      + this.username + '&password=' + this.password)
          .then(function(response){
                  if (response.body.status == 'success'){
                    this.successMessage = "Registered Successfuly";
                  }
                  else this.errorMessage = response.body.message;
                  this.username = this.password = "";
          })
    },
    login : function(){
      this.successMessage = "";
      this.$http.get(this.url + '/RecoverKey/username='
                     + this.username + '&password=' + this.password)
        .then(function(response){
                if (response.body.status == 'success'){
                  console.log(this.key = response.body.key);
                  this.loggedIn = true;
                }
                else console.log(this.errorMessage = response.body.message);
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
}
#loginButton{
  background-color: #F6A9CE;
  color:white;
  border:1px solid white;
  cursor:pointer;
}

#registerButton{
  background-color: #11CBD7;
  color:white;
  border:1px solid white;
  cursor:pointer;
}

#logoutButton{
  background-color: #FF9867;
  color:white;
  border:1px solid white;
  cursor:pointer;
}


input{
  width:200px;
  text-align:center;
  border:1px solid #E2DCD5;
}

button{
  width: 100px;
}

.error{
  color: #F03861;
}

.success{
  color: #11CBD7;
}
.logo {
    max-width:200px;
    width:200px;
}
</style>
