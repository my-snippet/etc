var contentHeight = 250; // What is the height of the static content of the page?
var curPage = 1; // What virtual 'page' of results are we on?
var $console; // For showing debug info

// Show a console message
 function log(msg) {
     $console.append('<p>' + msg + '</p>');
     $console.animate({
         scrollTop: 99999
     }, "fast"); // Scroll to bottom
 }

// Calculate the height of the scroll target based on page content
function calcScrollTarget() {
    var windowHeight = document.documentElement.clientHeight;
    var bodyHeight = $(document).height();
    var delta = bodyHeight - windowHeight - 50;
    log('Scroll target: ' + bodyHeight + ' (body content) - ' + windowHeight + ' (browser height) - 50 (buffer) = ' + delta);
    contentHeight = delta; // Update target amount
    $('div#scroll_guide').height(delta); // Update guide
}

// Load the next page of content
function loadContent() {
    if (curPage >= 15) {
        // Cap results
        contentHeight = 999999; // Move scroll target past end of page
    } else {
        // Simulate new results
        // In reality this would be an AJAX call, likely
        curPage++; // Next page
        var $result = $('div#result_wrapper').append('<p>Page ' + curPage + '</p>');
        for (var i = 1; i <= 21; i++) {
            $result.append('<div class="block">Page ' + curPage + ', result ' + i + '</div>');
        }
        $result.append('<p class="clear">.</p>');
        calcScrollTarget(); // Update scroll target
    }
}

$(document).ready(function() {
    $console = $('div#console'); // Store for future use
    // Create initial results
    var $result = $('div#result_wrapper').html('');
    for (var i = 1; i <= 21; i++) {
        $result.append('<div class="block">Result block ' + i + '</div>');
    }
    $result.append('<p class="clear">.</p>');

    calcScrollTarget(); // Set initial scroll target
    $(window).resize(calcScrollTarget); // If browser size changes, recalculate scroll target

    // monitor the window's scroll event
    $(window).scroll(function() {
        //log("Scroll detected: "+$(window).scrollTop()+".");
        if ($(window).scrollTop() > contentHeight) {
            log('Load more content');
            loadContent();
        }
    });
});
