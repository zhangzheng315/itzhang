function Triangle(m,ff,bb){
    let x='';
    var y=2*m;    
    switch(bb){
        case 1:
            for(var i=m;i>=0;i--){
                for(var j=0;j<=y;j++){
                    if(i==j || j+i==y || i==0){
                        x+=ff;
                    }else{
                        x+='   ';
                    }
                }
                x+='\n';
            }
            console.log(x);
            break;
        case 2:
            for(var i=m;i>=0;i--){
                for(var j=0;j<=y;j++){
                    if(i<=j && j+i<=y || i==0){
                        x+=ff;
                    }else{
                        x+='   ';
                    }
                }
                x+='\n';
            }
            console.log(x);
            break;
    }
    
}
function re(m,ff,bb){
    let x='';
    switch(bb){
        case 1:
            for(var i=0;i<m;i++){    
                for(var j=0;j<m;j++){
                    if(i==0||i==m-1){
                        x+=ff; 
                    }else if(j==0||j==m-1){
                        x+=ff;
                    }else{
                        x+="   ";
                    }             
                }
                x+='\n'
            }
            console.log(x);
            break;
            
        case 2:           
            for(var i=0;i<m;i++){    
                for(var j=0;j<m;j++){
                    x+=ff;      
                }
                x+='\n'
            }
            console.log(x);
            break;
    }
}  

function Trap(m,ff,bb){
    let x='';
    let y=3*m;
    switch(bb){
        case 1:
            for(var i=m;i>=0;i--){
                for(var j=0;j<=y;j++){
                    if(i==0 ||(i==m && j>=m && j<=2*m) || i==j || i+j==y){
                        x+=ff;
                    }else{
                        x+='   ';
                    }
                }
                x+='\n';
            }
            console.log(x);
            break;
        case 2:
            for(var i=m;i>=0;i--){
                for(var j=0;j<=y;j++){
                    if(  i<=j && i+j<=y){
                        x+=ff;
                    }else{
                        x+='   ';
                    }
                }
                x+='\n';
            }
            console.log(x);
    }
}

function diamond(m,ff,bb){
    var x='';
    m=m%2==0?m:m+1;
    let y=m/2;
        switch(bb){
        case 1:
            for(var i=m;i>=0;i--){
                for(var j=0;j<=m;j++){
                    if(i>=y && (i-j==y || i+j==m+y)){
                        x+=ff;
                    }else if(i<=y && (i+j==y || j-i==y)){
                        x+=ff;
                    }
                    else{
                        x+='   ';
                    }
                }
                x+='\n';
            }
            console.log(x);
            break;
        case 2:
            for(var i=m;i>=0;i--){
                for(var j=0;j<=m;j++){
                    if(Math.abs(i-j)<=y && i+j<=m+y && i+j>=y){
                        x+=ff;
                    }
                    else{
                        x+='   ';
                    }
                }
                x+='\n';
            }
            console.log(x);
    }
}   

function hui(m,ff,bb){
    let x='';
    var y=parseInt(m/3);
    switch(bb){
        case 1:
            for(var i=m;i>=0;i--){
                for(var j=0;j<=m;j++){
                    if( j==0 || j==m ){
                        x+=ff;
                    }else if(i==0 || i==m){
                        x+=ff;
                    }else if((i==y||i==2*y)&&(j>=y&&j<=y*2)){
                        x+=ff;
                    }else if((j==y||j==2*y)&&(i>=y&&i<=y*2)){
                        x+=ff;
                    }
                    else{
                        x+='   ';
                    }
                }
                x+='\n';
            }
            console.log(x);
            break;
        case 2:
            for(var i=0;i<=m;i++){    
                for(var j=0;j<=m;j++){
                    if(i>=y&&i<=2*y&&j>=y&&j<=y*2){
                        x+='   ';
                    }else if(j>=y&&j<=2*y&i>=y&&i<=2*y){
                        x+='   ';
                    }
                    else{
                        x+=ff;
                    }      
                }
                x+='\n'
            }
            console.log(x);
            break;
    }
}

function main(id,m,aa,bb){
    var ff;
    switch(aa){
        case 1:
            ff='  *';
            break;
        case 2:
            ff='  -';
            break;
        case 3:
            ff='  #';
            break;
    }
    switch(id){
        case 1:
            Triangle(m,ff,bb);
            break;
        case 2:
            re(m,ff,bb);
            break;
        case 3:
            Trap(m,ff,bb);
            break;
        case 4:
            diamond(m,ff,bb);
            break;
        case 5:
            hui(m,ff,bb);
            break;
    }
}

// main(1,7,3,1);

const readline = require('readline');
async function input(msg){
    return await new Promise((resolve,reject)=>{
        const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
        });
        rl.question(msg,(answer)=>{
            resolve(answer);
            rl.close();
        });
    })
}
(async()=>{
    var id =await input("三角形按1，正方形按2，梯形按3，菱形按4,回字按5\n");
    var mm =await input("请输入高度\n");
    var aa =await input("使用*按1，使用-按2，使用#按3\n");
    var bb =await input("空心按1，实心按2\n");
    // console.log(id,mm,aa,bb);
    main(Number(id),Number(mm),Number(aa),Number(bb))
})()


