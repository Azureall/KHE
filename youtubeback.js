chrome.browserAction.onClicked.addListener(function(tab) {
  // No tabs or host permissions needed!
  console.log('beep');
  chrome.tabs.executeScript({
    file: "youtube.js";
  });
});
