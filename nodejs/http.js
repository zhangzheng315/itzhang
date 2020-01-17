const net =require('net');
const fs =require("fs");
const server =net.createServer();

server.on("connection",(client)=>{
    console.log('鱼咬钩了，快收网');
    
    client.on("data",(data)=>{
        // console.log(data.toString());
        var str=data.toString();
        var index=str.indexOf('\n');
        var firstline=str.slice(0,index);
        const [method,url,ver]=firstline.split(' ');       
        if(url==='/admin'){
            var lstr1=str.trim();           
            var lin=lstr1.lastIndexOf('=');
            var llline=lstr1.slice(lin+1);
            
            if(fs.existsSync("./"+llline+".txt")){
                client.write("HTTP/1.1 200 OK\n");
                client.write("content-type:text/html;charset=utf-8\n\n"); 
                fs.readFile("./"+llline+".txt",(err,cont)=>{
                    client.write(`${cont}\n`);
                    client.end();
                })
                
            }else{
                client.write("HTTP/1.1 302 Found\n");
                client.write("content-type:text/html;charset=utf-8\n"); 
                client.write("Location:http://localhost:8001/login\n\n");
                client.end();
            }
        }
        if(url==='/login'){
            if(method=='GET'){ 
                client.write("HTTP/1.1 200 OK\n");
                client.write("content-type:text/html;charset=utf-8\n\n");               
                client.write("<h2>登录界面</h2>\n");
                client.write("<hr>\n");
                client.write("<form action='' method='post'>\n");
                client.write("用户名：<input type='text' placeholder='请输入用户名' name='uname'><br>\n");
                client.write("密&nbsp;&nbsp;&nbsp;&nbsp;码：<input type='password' name='pwd' placeholder='请输入密码'><br>\n");
                client.write("<input type='submit' value='提交'>\n");
                client.write('</form>\n');
                client.end();
            }
            if(method=='POST'){
                var lstr=str.trim();
                var lindex=lstr.lastIndexOf('\n');
                var lline=lstr.slice(lindex);
                if(lline.indexOf('&')!=-1){
                    var arr=lline.split('&');
                }
                if(arr[0].split('=')[1]=='admin' && arr[1].split('=')[1]=='123456'){
                    client.write("HTTP/1.1 200 Ok\n");
                    client.write("content-type:text/html;charset=utf-8\n");
                    let num=parseInt(Math.random()*1000000).toString(16);
                    fs.writeFile(num+'.txt',arr[0].split('=')[1],()=>{
                        client.write(`Set-cookie:SESSID=${num}\n\n`);
                        client.write("<meta http-equiv='refresh' content='1;url=http://localhost:8001'>\n");
                        client.write("登陆成功\n");
                        client.end();
                    });                    
                }
                
            }
            
        }
        if(url=='/'){
            client.write("HTTP/1.1 200 OK\n");
            client.write("content-type:text/html;charset=utf-8\n\n");
            client.write("<h1>welcome</h1><a href='/admin'>进入管理后台</a>\n");        
            client.end();
        }

        
    })   
})
server.listen(8001,()=>{
    console.log('服务启动成功');
})