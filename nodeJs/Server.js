var http = require('http');
var url = require('url');

function start(handle, route){
  //createServer에 인수로 넣을 함수
  //서버 구동시 실행할 내용을 작성
  function onRequest(request, response){
    console.log("input Server localhost:3000");   //서버 호출시 실행
    var pathname = url.parse(request.url).pathname;
    route(handle, pathname, response);
  }

  var server = http.createServer(onRequest);    //서버생성.. 실행방식을 매개변수로 전달

  server.listen(3000, function(){               //서버에서 응답대기
    console.log("start Server localhost:3000");
  })
}

exports.start = start;

















// var app = http.createServer(function(request,response){
//     var _url = request.url;

//     //var queryData = url.parse(_url, true).query;
//     //url에서 queryString의 데이터를 객체형식으로 가져옴 (?이후의 데이터)
//     //console.log(queryData.id);
//     //전달값이 ?id=HTML이면 id의 값인 HTML이 출력됨

//     console.log(_url);

//     if(_url == '/'){
//       url = '/index.html';
//     }
//     if(_url == '/favicon.ico'){
//       return response.writeHead(404);
//     }
//     response.writeHead(200);

//     //화면에 출력할것
//     response.end(fs.readFileSync(__dirname + _url));    //파일을 출력
//     //response.end(queryData.id);   //사용자가 입력한 문자열출력
// });
// app.listen(3000);



/*
http://test.org:3000/main?id=HTML&page=12
http : 통신규약
test.org : 도메인주소(host)
3000 : port번호
main : path
? : 쿼리스트링앞에 적어줘야할 약속된 문자
= : 이름과 값을 구분하는 약속된 문자
& : 쿼리스트링의 문자를 구분하는 약속된 문자
*/