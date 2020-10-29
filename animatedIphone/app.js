const card = document.querySelector('.card');
const container = document.querySelector('.container')

const title = document.querySelector('.title');
const iphone = document.querySelector('.iphone img');
const purchase = document.querySelector('.purchase');
const variants = document.querySelector('.variants');
const description = document.querySelector('.info h3');


container.addEventListener('mousemove' , (e) => {
    let xAxis = (window.innerWidth / 2 -e.pageX) / 20;
    let yAxis = (window.innerHeight / 2 - e.pageY) / 20;
    
    card.style.transform = `rotateY(${xAxis}deg) rotateX(${yAxis}deg)`
})
//Animate in
container.addEventListener('mouseenter', (e) => {
    card.style.transition = 'none';
    
    title.style.transform = 'translateZ(150px)';
    iphone.style.transform = 'translateZ(200px) rotateZ(-45deg)';
    purchase.style.transform = 'translateZ(150px)';
    variants.style.transform = 'translateZ(100px)';
    description.style.transform = 'translateZ(125px)';
    
})
//Animate out
container.addEventListener('mouseleave', (e) => {
    card.style.transition = 'all 0.75s ease';
    card.style.transform = `rotateY(0deg) rotateX(0deg)`;
    
    title.style.transform = 'translateZ(0px)';
    iphone.style.transform = 'translateZ(0px) rotateZ(0deg)';
    purchase.style.transform = 'translateZ(0px)';
    variants.style.transform = 'translateZ(0px)';
    description.style.transform = 'translateZ(0px)';
})