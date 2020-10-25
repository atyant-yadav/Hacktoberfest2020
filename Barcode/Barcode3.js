JsBarcode("#barcode","Hello World!!!",{
    background:"#f7db4f",
    lineColor:"#000000"
  });
  function generate()
  {
    let val = document.querySelector("input").value
    if(val == "") 
      {
        val = "Hello World !!!"
      }
    JsBarcode("#barcode",val ,{
      background:"#f7db4f",
      lineColor:"#000000"
    });
  }