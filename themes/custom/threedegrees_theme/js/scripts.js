(function($){
  /* $ is mapped to Drupal's version of jQuery in here */

  $(function(){
    /* document is ready in here */

/*  CarouFredSel: a circular, responsive jQuery carousel.
  Configuration created by the "Configuration Robot"
  at caroufredsel.frebsite.nl
*/
$(".views-field-field-slideshow-images ul").carouFredSel({
  width: 900,
  align: false,
  height: 370,
  items: {
    visible: 1,
    width: 900,
    height: 370
  },
  pagination: "div.pagination",
  scroll: {
        fx: "crossfade",
        duration: 1000
  }
});

  });

})(jQuery);
