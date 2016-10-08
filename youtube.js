//var logger = function() {console.log($(".comment-renderer-text-content").text());}

//setInterval(logger, 5000);

var $script = $("<script> function btnfnc(){alert('Hello');}</script>");

$("html").append($script);

var logger2 = function () {
  $('.comment-renderer-text-content').each(function()
  {
    if (censor($(this).text())){
      $(this).hide();
      $(this).parent().append("<input class='censorship-block' onClick='btnfnc()' type='button' value='This comment was flagged as offensive. Click to show.'/>");
      // $tmp.appendTo($(this).parent());
    }
  });
}

var censor = function(input){
  var indx = input.search("the");
  if (indx == -1){
    return false;
  }
  else {
    return true;
  }
}



setInterval(logger2, 5000);


// chrome.runtime.onMessage.addListener(
//   function(request, sender, sendResponse) {
//     if( request.message === "clicked_browser_action" ) {
//       var firstHref = $("a[href^='http']").eq(0).attr("href");
//
//       console.log(firstHref);
//     }
//   }
// );
