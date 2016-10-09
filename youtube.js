//var logger = function() {console.log($(".comment-renderer-text-content").text());}

//setInterval(logger, 5000);



var $script = $("<script> function btnfnc(clicked_id){alert(clicked_id);}</script>");

$("html").append($script);

var logger2 = function () {
  $('.comment-renderer-text-content').each(function()
  {
    if(!($(this).hasClass("flagged-comment"))){
      if (censor($(this).text())){
        $(this).addClass("flagged-comment");
        $(this).hide();
        var temp = $(this).text();
        $(this).parent().append("<input id='bitchesbecray' class='censorship-block' onClick='btnfnc(this.id)' type='button' value='This comment was flagged as offensive. Click to show.'/>");
        $("#bitchesbecray").attr("id", temp);
        // $tmp.appendTo($(this).parent());
      }
    }
  });
}

var censor = function(input){
  var hRate = 0;
  var strin = input.split(" ");
  for (j = 0; j < strin.length; j++){
    hRate += getRate(strin[j].toLowerCase());
  }

  hRate = hRate/(strin.length);

  if (hRate >= .5) {return true;}
  return false;

  // var indx = input.search("the");
  // if (indx == -1){
  //   return false;
  // }
  // else {
  //   return true;
  // }
}

var getRate = function(input){
  console.log(input);
  for (i = 0; i < wordDatabase.length; ++i){
    if(input.includes(wordDatabase[i].word)){
      console.log(wordDatabase[i].rating);
      return wordDatabase[i].rating;
    }
  }
  return 0;
}



setInterval(logger2, 5000);

var wordDatabase = [
  {word:"hate", rating:2},
  {word:"faggot", rating:5},
  {word:"homo", rating:5},
  {word:"fag", rating:5},
  {word:"fuck", rating:5},
  {word:"weiner", rating:5},
  {word:"gay", rating:4},
  {word:"fucking", rating:4},
  {word:"dumbass", rating:5},
  {word:"dumb", rating:1},
  {word:"idiot", rating:4},
  {word:"moron", rating:4},
  {word:"weeb", rating:2},
  {word:"dummie", rating:4},
  {word:"dislike", rating:1},

  {word:"you", rating:1},
  {word:"asshole", rating:4},
  {word:"ass", rating:2},
  {word:"don't", rating:-3},
  {word:"dont", rating:-3},
  {word:"no", rating:-3},
  {word:"doesn't", rating:-3},
  {word:"doesnt", rating:-3},
  {word:"not", rating:-3},
  {word:"stop", rating:-3}

]
