import express from 'express';
import { engine } from 'express-handlebars';
import mongoose from 'mongoose';
import admin from './routes/admin.js';
import path from 'path';
import { fileURLToPath } from 'url';
import session from 'express-session';
import flash from 'connect-flash';
import "./models/Postagem.js"
import "./models/Categoria.js"
import usuarios from "./routes/usuario.js"
import passport from 'passport';
import "./config/auth.js"
authConfig(passport);

const Categoria = mongoose.model("categorias")
const Postagem = mongoose.model("postagens")


// Simula __dirname
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const app = express();

  // Configurações
    app.use(session({
      secret: "cursodenode",
      resave: true,
      saveUninitialized: true
    }))
    
  //Configurando o passport
    app.use(passport.initialize())
    app.use(passport.session())
    app.use(flash())
  //Middleware
    app.use((req, res, next) => {
      //Criando as variáveis globais
      res.locals.success_msg = req.flash("success_msg")
      res.locals.error_msg = req.flash("error_msg")
      res.locals.error = req.flash("error")
      //armazena dados do usuário logado, caso não exista será passado o valor null para a variável.
      res.locals.user = req.user || null;
      next()
    })
    app.use(express.urlencoded({ extended: true }));
    app.use(express.json());

  // Handlebars
    app.engine('handlebars', engine({
      runtimeOptions: {
        //para permitir que o handlebars acesse os atributos herdados de objetos
        allowProtoPropertiesByDefault: true,
        allowProtoMethodsByDefault: true
      }
    }));
    app.set('view engine', 'handlebars');
    app.set('views', './views');

  //Mongoose
    mongoose.Promise = global.Promise;
    mongoose.connect('mongodb://127.0.0.1:27017/blogapp').then(() =>{
      console.log("Conectado ao mongo")
    }).catch((err) => {
      console.log("Erro ao se conectar: " + err)
    })

  // Public
    app.use(express.static(path.join(__dirname, 'public')));

  // Rotas
    app.get('/', (req, res) => {
      Postagem.find().populate("categoria").sort({data: "desc"}).then((postagens) => {
        res.render("index", {postagens: postagens})
      }).catch((err) => {
        req.flash("error_msg", "Houve um erro interno")
        res.redirect("/404")
      })
    })

    app.get("/postagem/:slug", (req, res) => {
      Postagem.findOne({slug: req.params.slug}).then((postagem) => {
        if(postagem){
          res.render("postagem/index", {postagem: postagem})
        }
        else{
          req.flash("error_msg", "Esta postagem não existe")
          res.redirect("/")
        }
      }).catch((err) => {
        req.flash("error_msg", "Houve um erro interno")
        res.redirect("/")
      })
    })

    app.get("/404", (req, res) => {
      res.send("Erro 404")
    })

    app.get("/categorias", (req, res) => {
      Categoria.find().then((categorias) => {
        res.render("categorias/index", {categorias: categorias})
      }).catch((err) => {
        req.flash("error_msg", "Houve um erro interno ao listar as categorias")
        res.redirect("/")
      })
    })

    app.get("/categorias/:slug", (req, res) => {
      Categoria.findOne({slug: req.params.slug}).then((categoria) => {
        if (categoria) {
            Postagem.find({categoria: categoria._id}).then((postagens) => {
            res.render("categorias/postagens", {postagens: postagens, categoria: categoria})
          }).catch((err) => {
            req.flash("error_msg", "Houve um erro ao listar os posts")
            res.redirect("/")
          })
        } else {
          req.flash("error_msg", "Esta categoria não existe")
          res.redirect("/")
        }
      }).catch((err) => {
        req.flash("error_msg", "Erro interno ao carregar esta categoria")
        res.redirect("/")
      })
    })

    app.use('/admin', admin);
    app.use("/usuarios", usuarios)
  // Outros

    app.listen(8081, () => {
      console.log('Servidor rodando em http://localhost:8081');
    });
