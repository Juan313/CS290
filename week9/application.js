var express = require('express');
var mysql = require('./dbcon.js');
var session = require('express-session');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false}));
app.use(bodyParser.json());
app.use(session({secret:'SuperSecretePassword'}));

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 31385);

app.get('/',function(req,res,next){
  var context = {};
  req.session.id=0;
  req.session.list = [];

  context.list = [];
  res.render('home',context);
});

app.post('/',function(req,res) {
  var context = {};
  context.list = [];
  req.session.list = req.session.list || [];
  if (req.body["Add exercise"])
  {
    req.session.list.push({"name": req.body.name, "time": req.body.times,
                           "weight": req.body.weight, "date": req.body.date,
                           "unit": req.body.unit, "id": req.session.id});
    req.session.id++; 
  }
  context.list = req.session.list; 
  res.render('home',context);  
  
});

app.get('/reset-table',function(req,res,next){
  var context = {};
  mysql.pool.query("DROP TABLE IF EXISTS workouts", function(err){ //replace your connection pool with the your variable containing the connection pool
    var createString = "CREATE TABLE workouts("+
    "id INT PRIMARY KEY AUTO_INCREMENT,"+
    "name VARCHAR(255) NOT NULL,"+
    "reps INT,"+
    "weight INT,"+
    "date DATE,"+
    "lbs BOOLEAN)";
    mysql.pool.query(createString, function(err){
      context.results = "Table reset";
      res.render('reset',context);
    })
  });
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});
