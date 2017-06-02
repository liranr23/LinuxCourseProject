<template>
  <div class="orderMenu">

    <h1> Choose movie and location </h1>
    <h2>Movies:</h2>

    <table cellpadding="10">
        <tbody>
            <tr>
                <th>Title</th>
                <th>Producer</th>
                <th>Year</th>
                <th>Link</th>
            </tr>
            <tr v-for="movie in movies" v-on:click="selectedMovie=movie">
                <td>{{movie.title}}</td>
                <td>{{movie.producer}}</td>
                <td>{{movie.year}}</td>
                <td>{{movie.link}}</td>
            </tr>
        </tbody>
    </table>


    <h2> Locations </h2>
    <table cellpadding="10">
        <tbody>
            <tr>
                <th>Country</th>
                <th>City</th>
                <th>Address</th>
            </tr>
            <tr v-for="location in locations" v-on:click="selectedLocation=location">
                <td>{{location.country}}</td>
                <td>{{location.city}}</td>
                <td>{{location.address}}</td>
            </tr>
        </tbody>
    </table>

    <button v-on:click="order">Order</button>

    <h1> Order History </h1>

    <div> <!-- Will be another table once the api is complete -->
        {{orders}}
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
       selectedMovie: undefined,
       selectedLocation: undefined,
       selectedOrder: undefined
      }
        
    },
    methods: {
           order: function(){
               console.log("Ordered: ",this.selectedMovie.id ,this.selectedLocation.id);
               //Here should request @ localhost/Order/

               //And then:
               this.refreshHistory();
           },
           refreshHistory: function(){
               this.$http.get('http://localhost/History/key=' + this.userKey)
                    .then(function(response){
                //if (response.body.status == "success")
                    console.log(this.orders = response);
            })
           }
        },
        created: function(){
            //All Movies
            this.$http.get('http://localhost/Movies/')
            .then(function(response){
                if (response.body.status == "success")
                    console.log(this.movies = response.body.movies);
                    
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

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

</style>
