//var logger = function() {console.log($(".comment-renderer-text-content").text());}

//setInterval(logger, 5000);

var i = 0

var logger2 = function () {
  $('.comment-renderer-text-content').each(function()
  {
    console.log($(this).text());
    console.log(i);
    i += 1;
    if (censor($(this).text())){
      $(this).parent().parent().parent().hide();
    }
  })
}

setInterval(logger2, 5000);

var censor = function(input){
  var indx = input.search("fuck");
  if (indx == -1){
    return false;
  }
  else {
    return true;
  }
}
