<template>
    <div class="row">
        <div class="col-8">
            <div class="row align-items-center header">
                <img  src="../assets/003-popcorn.svg">
                <h2> Order a ticket </h2>
            </div>
            <h3>Movies:</h3>
            <table cellpadding="10">
                <tbody>
                    <tr>
                        <th>Title</th>
                        <th>Producer</th>
                        <th>Year</th>
                        <th>Link</th>
                    </tr>
                    <tr 
                    :class="{selected: movie.id == selectedMovieID}"
                    class="option"  v-for="movie in movies" v-on:click="selectedMovieID=movie.id">
                        <td>{{movie.title}}</td>
                        <td>{{movie.producer}}</td>
                        <td>{{movie.year}}</td>
                        <td><a :href="movie.link"> Link</a></td>
                        
                    </tr>
                </tbody>
            </table>

            <h3> Locations </h3>
            <table cellpadding="10">
                <tbody>
                    <tr>
                        <th>Country</th>
                        <th>City</th>
                        <th>Address</th>
                    </tr>
                    <tr 
                    :class="{selected: location.id == selectedLocationID}"
                    class="option"  v-for="location in locations" v-on:click="selectedLocationID=location.id">
                        <td>{{location.country}}</td>
                        <td>{{location.city}}</td>
                        <td>{{location.address}}</td>
                    </tr>
                </tbody>
            </table>

            <button id="orderButton" v-on:click="order">Order</button>
            <div class="row">
              <p class="error" >{{orderErrorMsg}}</p>
              <p class="success"> {{orderSuccessMsg}}</p>
            </div>
        </div>
        <div class="col-4">
            <div class="row align-items-center header">
                <img  src="../assets/004-tickets.svg">
                <h2> History </h2>
            </div>
            <h3> Past Orders </h3>
            <table cellpadding="10">
                <tbody>
                    <tr>
                        <th>Order ID</th>
                        <th>Movie ID</th>
                        <th>Location ID</th>
                        <th>Canceled</th>
                    </tr>
                    <tr
                    :class="{selected: order.id == selectedOrderID}" 
                    class="option" v-for="order in orders" v-on:click="selectedOrderID=order.id">
                        <td>{{order.id}}</td>
                        <td>{{order.movieID}}</td>
                        <td>{{order.locationID}}</td>
                        <td>{{order.canceled}}</td>
                    </tr>
                </tbody>
            </table>
            <button id="cancelButton" v-on:click="cancelOrder">Cancel</button>
            <div class="row">
              <p class="error" >{{cancelErrorMsg}}</p>
              <p class="success"> {{cancelSuccessMsg}}</p>
            </div>
        </div>
    </div>
</template>

<script>
export default {
  name: 'orderMenu',
  props: ['userKey'],
  data() {
      return {
       movies: [],
       locations: [],
       orders: [],
       selectedMovieID: NaN,
       selectedLocationID: NaN ,
       selectedOrderID: NaN,
       cancelErrorMsg: "",
       cancelSuccessMsg: "",
       orderErrorMsg: "",
       orderSuccessMsg:""
      }
        
    },
    methods: {
           order: function(){
               this.orderErrorMsg = this.orderSuccessMsg = "";
               this.$http.get("http://localhost/Order/key=" + this.userKey + 
                            "&movieID=" + this.selectedMovieID + 
                            "&locationID=" +this.selectedLocationID)
                            .then(function(response){
                                console.log(response);
                                if (response.body.status == "success"){
                                    this.orderSuccessMsg = response.body.message;
                                    this.refreshHistory();
                                }
                                else this.orderErrorMsg = response.body.message;

                                this.selectedOrderID = this.selectedMovieID =  NaN;
                            })
           },
           refreshHistory: function(){
               this.$http.get('http://localhost/History/key=' + this.userKey)
                    .then(function(response){
                        if (response.body.status == "success")
                            this.orders = response.body.orders;
                    })
           },
           cancelOrder: function(){
            this.cancelErrorMsg = this.cancelSuccessMsg = ""
            this.$http.get('http://localhost/Cancel/key=' + this.userKey + '&orderID=' + this.selectedOrderID)
                    .then(function(response){
                        console.log(response);
                        if (response.body.status == "success"){
                            this.cancelSuccessMsg = response.body.message;
                            this.refreshHistory();
                        }
                        else{
                            this.cancelErrorMsg = response.body.message;
                        }
                        this.selectedOrderID = NaN;
                        })
           }
        },
        created: function(){
            //Order History
            this.refreshHistory();
            //All Movies
            this.$http.get('http://localhost/Movies/')
            .then(function(response){
                if (response.body.status == "success")
                    this.movies = response.body.movies;
                else{
                    this.orderErrorMsg = "Error Loading Movies";
                }
            })
            //All locations
            this.$http.get('http://localhost/Locations/')
            .then(function(response){
                if (response.body.status == "success")
                    this.locations = response.body.locations;
            })

            
        },

}
</script>

<style>
    #cancelButton{
        background-color: #F6A9CE;
        color:white;
        border:1px solid white;
        cursor:pointer;
    }

    #orderButton{
        background-color: #11CBD7;
        color:white;
        border:1px solid white;
        cursor:pointer;
        
    }

    .option{
         cursor:pointer;
         background-color: #FBF7F7;
    }

    .option:hover{
        background-color:#FDDD8A;
    }

    .selected{
        background-color:#9EFCB4;
        
    }

    .header{
        margin-bottom:30px;
    }
    img {
        max-width:60px;
    }

    h2 {
        margin-bottom:15px;
    }
    table{
        margin-bottom:50px;
    }

    th{
        background-color: #DC3737;
        color:white;
        border:1px solid white;
    }
    td {
        border:1px solid white;
    }
</style>
