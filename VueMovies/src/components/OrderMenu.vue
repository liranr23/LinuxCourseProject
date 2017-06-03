<template>
  <div class="orderMenu container">
    <div class="row">
        <div class="col">
            <h2> Order a ticket </h2>
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

            <button v-on:click="order">Order</button>
        </div>
        <div class="col">
            <h2> Order History </h2>

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
            <button v-on:click="cancelOrder">Cancel</button>
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
       selectedOrderID: NaN
      }
        
    },
    methods: {
           order: function(){
               //Here should request @ localhost/Order/
               this.$http.get("http://localhost/Order/key=" + this.userKey + 
                            "&movieID=" + this.selectedMovieID + 
                            "&locationID=" +this.selectedLocationID)
                            .then(function(response){
                                console.log(response);
                                if (response.body.status == "success")
                                this.refreshHistory();
                            })
               //And then:
           },
           refreshHistory: function(){
               this.$http.get('http://localhost/History/key=' + this.userKey)
                    .then(function(response){
                if (response.body.status == "success")
                    this.orders = response.body.orders;
            })
           },
           cancelOrder: function(){

               //  Here should request @ localhost/Cancel/
            this.$http.get('http://localhost/Cancel/key=' + this.userKey + '&orderID=' + this.selectedOrderID)
                    .then(function(response){
                        console.log(response);
                if (response.body.status == "success")
                    this.refreshHistory();
            })
               //And then:
               this.refreshHistory();
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
    .option{
         cursor:pointer;
    }

    .option:hover{
        background-color:red;
        color:white;
    }

    .selected{
        background-color:green;
        color:white;
    }
    h2{
        margin-bottom: 20px;
    }

    table{
        margin-bottom:15px;
    }
</style>
