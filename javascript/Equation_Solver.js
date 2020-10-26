//https://leetcode.com/problems/solve-the-equation/

/**
 * @param {string} equation
 * @return {string}
 */
var solveEquation = function(equation) {
    let leftSide = null;
    numCont = null
    onX =null
let rightSide = 0;
let xCoefficinet=[]
let xSigns = []
let numCoefficient=[]
let numSign=[]
let numStr="";
let i=0;
let equalsToIndex;
let currentSign=null;

let equationLen=equation.length-1;
while(i<=equationLen){
    result=0;
    
    if(!isNaN(equation[i])){
        
        
        if(numCont){
            numStr +=equation[i]
        }
        else{
            numCont=true;
            numStr +=equation[i]
        }
        
        if(i==0 || i==equalsToIndex+1){
            if(leftSide==null){
            numSign.push('+')
            }
            else{
                numSign.push('-')
            }
        }

        if(i==equationLen){
            console.log(numStr)
            numCoefficient.push(parseInt(numStr))
            if(i!=equalsToIndex+1 && i!=0)
            if(leftSide==null){
                numSign.push(currentSign)
                }
                else{
                    numSign.push(getInverSign(currentSign))
                }
        }
       
    }

    else if(equation[i]=='+' || equation[i]=='-'){
        
        if(numCont){
            numCoefficient.push(parseInt(numStr))
            numStr=""
            numCont=false
            if(currentSign!=null){
            if(leftSide==null){
                numSign.push(currentSign)
                }
                else{
                    numSign.push(getInverSign(currentSign))
                }
        }
    }
        currentSign = equation[i]

    }

    else if(equation[i]=='x'){
        

        if(numCont){
            
            if(currentSign==null){
                console.log("hre")
                numSign.pop()
                if(leftSide==null){
                    xSigns.push('-')
                    }
                else{
                    xSigns.push('+')
                    }
                xCoefficinet.push(parseInt(numStr))
                numStr=""; 
                numCont=false;      
            }
            else{
                xCoefficinet.push(parseInt(numStr))
                numStr=""; 
                numCont=false; 
                if(leftSide==null){
                    xSigns.push(getInverSign(currentSign));
                }
                else{
                    xSigns.push(currentSign)
                }
            }
            
        }

    
        else if(i==0 || i==equalsToIndex+1){
            if(leftSide==null){
                xSigns.push('-')
                }
            else{
                xSigns.push('+')
                }
            xCoefficinet.push(1)
        }

        else{
            if(leftSide==null){
                xSigns.push(getInverSign(currentSign))
                }
            else{
                xSigns.push(currentSign)
                }
            xCoefficinet.push(1)

        }
}

    else if(equation[i]=='='){
        
        if(numCont){
            numCoefficient.push(parseInt(numStr))
            numSign.push(currentSign)
            numStr=""
            numCont=false;
        }
        currentSign=null
       equalsToIndex=i; 
       leftSide=0;
       

    }
    i+=1;
}
    console.log(numCoefficient)
    console.log(numSign)
    leftSide= computeResult(numCoefficient,numSign)
rightSide = computeResult(xCoefficinet,xSigns);
console.log(rightSide+" "+leftSide)
if(leftSide==0 && rightSide==0){
    return "Infinite solutions"
}
else if(leftSide!=0 && rightSide==0){
    return "No solution"
}
else if(leftSide==0 && rightSide!=0){
    return "x=0"
}
else{
    return "x="+leftSide/rightSide
}


};

function computeResult(coefficientArray , signArray){
result=0
if(coefficientArray.length==0){
    
    return 0
}
for(i=0;i<coefficientArray.length;i++){
    if(signArray[i]=='+'){
        result+=coefficientArray[i];
    }
    else{
        result-=coefficientArray[i];
    }
}
return result


}
function getInverSign(sign){
if(sign=='+'){
    return '-'
}
else{
    return '+'
}
}


