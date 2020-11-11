function discounter(price, vouchercode, distance, tax){

    let discount
    if(vouchercode == 'HACKTOBERFEST2020' && price > 50000){
        discount =  price * 50 / 100
        discount <= 150000
    } else if(vouchercode == 'HACKTOBER' && price > 70000){
        discount = price * 30 / 100
        discount = 100000
    }else{
        discount = 0
    }

    let distancePrice
    if(distance < 2 && distance > 0){
        distancePrice = 2 * 1000;
    }else{
        distancePrice = (distance - 2) * 3000 + 2000
    }

    
    let countAll
    if(tax == true){
        let total  = ((price - discount) + distancePrice) 
        let tax = total * 2 / 100
        countAll = total -tax

    }else {
        countAll (price - discount) + distancePrice
    }

    return countAll

    
}



console.log(discounter(60000, 'HACKTOBERFEST2020', 3, true))



