
<!DOCTYPE html>
<html>
  <head>
    <style>
	#head{
		text-align:center;
		font-family: Verdana, Arial, Helvetica, sans-serif; 
	}
       #map {
        height: 400px;
        width: 100%;
       }
    </style>
  </head>
  <body>
    <h3 id="head">HACK4GOOD</h3>
	    <div id="map"></div>
	 <script>
	
      function initMap() {
		var divimg1=document.getElementById('image1');
		var divimg2=document.getElementById('image2');
		var divimg3=document.getElementById('image3');
		var divimg4=document.getElementById('image4');
		
        var uluru1 = {lat: 12.917269, lng: 77.622753};
		var uluru2= {lat:12.915955,lng:77.614932};
		var uluru3= {lat:12.915369,lng:77.638450};
		
		var map = new google.maps.Map(document.getElementById('map'), {
          zoom: 14,
          center: uluru1
        });
		var density=1;
		var density2=5;
		var density3=11;
		var density4=6;
		var denseicon = {
		url: 'http://maps.google.com/mapfiles/kml/shapes/caution.png', // url
		scaledSize: new google.maps.Size(50, 50) // scaled size
		};
		var peaceicon = {
		url:'http://maps.google.com/mapfiles/kml/paddle/go.png',
		scaledSize: new google.maps.Size(50, 50) 
		};
		if (density>10 || density2 >10 || density3> 10 || density4>10)
		{
		  var marker1 = new google.maps.Marker({
          position: uluru1	,
		  icon:denseicon,
          map: map,
		  title : 'SILK BOARD JUNCTION'
			});
		  
		var infowindow = new google.maps.InfoWindow({
          content: '<div style="text-align:center;color:#e22f0f;"><b>TRAFFIC CONGESTED !</b></div>'
			});
		  marker1.addListener('mouseover', function() {
          infowindow.open(map, marker1);
			});
		marker1.addListener('mouseout', function(event) {
		infowindow.close(map, marker1);
			});
		}
		else
		{
        var marker1 = new google.maps.Marker({
          position: uluru1,
		  icon:peaceicon,
          map: map,
		  title : 'SILK BOARD JUNCTION'
        });
		var infowindow = new google.maps.InfoWindow({
          content: '<div style="text-align:center;color:#15ed0e;"><b>TRAFFIC PEACEFUL :)</b></div>'
        });
		 marker1.addListener('mouseover', function() {
          infowindow.open(map, marker1);
        });
		marker1.addListener('mouseout', function(event) {
		infowindow.close(map, marker1);
		});
		
		}
	{
		
			var marker2=new google.maps.Marker({
          position: uluru2,
		  icon:peaceicon,
          map: map,
		  title : 'Junction 2'
			});
			var infowindow1 = new google.maps.InfoWindow({
			content: '<div style="text-align:center;color:#15ed0e;"><b>TRAFFIC PEACEFUL :)</b></div>'
			});
			marker2.addListener('mouseover', function() {
			infowindow1.open(map, marker2);
			});
			marker2.addListener('mouseout', function(event) {
			infowindow1.close(map, marker2);
			});
		
			var marker3=new google.maps.Marker({
          position: uluru3,
		  icon:peaceicon,
          map: map,
		  title : 'Junction 3'
			});
			var infowindow2 = new google.maps.InfoWindow({
			content: '<div style="text-align:center;color:#15ed0e;"><b>TRAFFIC PEACEFUL :)</b></div>'
			});
			marker3.addListener('mouseover', function() {
			infowindow2.open(map, marker3);
			});
			marker3.addListener('mouseout', function(event) {
			infowindow2.close(map, marker3);
			});
			
	}
		marker1.addListener('click', function(event) {
		var img1=document.createElement("img");
		var img2=document.createElement("img");
		var img3=document.createElement("img");
		var img4=document.createElement("img");
		var par1=document.createElement("p");
		var par2=document.createElement("p");
		var par3=document.createElement("p");
		var par4=document.createElement("p");
		divimg1.appendChild(img1);
		divimg1.appendChild(par1);
		img1.src="images/predictions1.png";
		img1.style="width:50%;height:300px;";
		par1.innerHTML = "Predicted  traffic density in Lane 1 : "+density;
		
		divimg2.appendChild(img2);
		divimg2.appendChild(par2);
		img2.src="images/predictions2.png";
		img2.style="width:50%;height:300px;";
		par2.innerHTML = "Predicted  traffic density in Lane 2 : "+density2;
		
		divimg3.appendChild(img3);
		divimg3.appendChild(par3);
		img3.src="images/predictions3.png";
		img3.style="width:50%;height:300px;";
		par3.innerHTML = "Predicted  traffic density in Lane 3 : "+density3;
		
		divimg4.appendChild(img4);
		divimg4.appendChild(par4);
		img4.src="images/predictions4.png";
		img4.style="width:50%;height:300px;";
		par4.innerHTML = "Predicted  traffic density in Lane 4 : "+density4;
		
		
		
			
			
			});
		
		
      }
    </script>
	<div id="image1">
	</div>
	<div id="image2">
	</div>
	<div id="image3">
	</div>
	<div id="image4">
	</div>
    <script async defer
    src="https://maps.googleapis.com/maps/api/js?key=AIzaSyAa-XiOfYNqBHBvkMrSFQxanwgXoYZmulw&callback=initMap">
    </script>
  </body>
</html>