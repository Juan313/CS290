var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false}));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 31346);


app.get('/',function(req,res){
  var context ={};
  var receivedPara = [];
  for (var q in req.query) {
    receivedPara.push({'name':q, 'value':req.query[q]});
  }
  context.dataList = receivedPara;
  res.render('getRequest',context);
});

app.post('/',function(req,res){
  var context ={};
  var receivedPara = [];
  // req.body won't work unless bodyParser is setup
  for (var q in req.body) {
    receivedPara.push({'name':q, 'value':req.body[q]});
  }
  context.dataList2 = receivedPara;
  res.render('postRequest',context);
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});
