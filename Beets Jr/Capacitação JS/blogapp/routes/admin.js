import { Router } from 'express';
import mongoose from 'mongoose';
import "../models/Categoria.js";
import "../models/Postagem.js";
const Categoria = mongoose.model("categorias");
const Postagem = mongoose.model("postagens");
import { eAdmin } from "../helpers/eAdmin.js";

const router = Router();

router.get('/', (req, res) => {
    res.render("admin/index");
});


router.get('/categorias', eAdmin, (req, res) => {
    Categoria.find().sort({date:"desc"}).then((categorias) => {
        res.render("admin/categorias", {categorias: categorias});
    }).catch((err) => {
        req.flash("error_msg", "Houve um erro ao listar as categorias")
        res.redirect("/admin")
    })
});

router.get('/categorias/add', eAdmin, (req, res) => {
    res.render("admin/addcategorias");
});

router.post('/categorias/nova', eAdmin, (req, res) => {
    let erros = []

    if(!req.body.nome || typeof req.body.nome == undefined || req.body.nome == null)
    {
        erros.push({texto: "Nome inválido"})
    }

    if(!req.body.slug || typeof req.body.slug == undefined || req.body.slug == null)
    {
        erros.push({texto: "Slug inválido"})
    }

    if (req.body.nome.length < 2) {
        erros.push({texto: "Nome da categoria muito pequeno"})
    }

    if(erros.length > 0)
    {
        res.render('admin/addcategorias', {erros: erros})
    } else {
        const novaCategoria = {
            nome: req.body.nome,
            slug: req.body.slug,
        }

        new Categoria(novaCategoria).save().then(() => {
            //Passando valores para as variaveis globais em caso de sucesso ou erro na criação de uma categoria
            req.flash("success_msg", "categoria criada com sucesso")
            res.redirect("/admin/categorias")
        }).catch((err) => {
            req.flash("error_msg", "houve um erro ao salvar a categoria")
            res.redirect('/admin')
        })
    }

})

router.get("/categorias/edit/:id", eAdmin, (req, res) => {
    Categoria.findOne({_id:req.params.id}).then((categoria) => {
        res.render("admin/editcategorias", {categoria: categoria})
    }).catch((err) => {
        req.flash("error_msg", "Esta categoria não existe")
        res.redirect("/admin/categorias")
    })
})

router.post("/categorias/edit", eAdmin, (req, res) => {
    Categoria.findOne({_id: req.body.id}).then((categoria) => {
        let erros = []

        if(!req.body.nome || typeof req.body.nome == undefined || req.body.nome == null)
        {
            erros.push({texto: "Nome inválido"})
        }

        if(!req.body.slug || typeof req.body.slug == undefined || req.body.slug == null)
        {
            erros.push({texto: "Slug inválido"})
        }

        if (req.body.nome.length < 2) {
            erros.push({texto: "Nome da categoria muito pequeno"})
        }

        if(erros.length > 0)
        {
            res.render('admin/editcategorias', {erros: erros, categoria})
            return;
        } else {
            categoria.nome = req.body.nome
            categoria.slug = req.body.slug
            categoria.save().then(() =>{
                req.flash("success_msg", "categoria editada com sucesso")
                res.redirect("/admin/categorias")
            }).catch((err) => {
                req.flash("error_msg", "Erro interno ao editar a categoria")
                res.redirect("/admin/categorias")
            })
        }

    }).catch((err) => {
        req.flash("error_msg", "Houve um erro ao editar a categoria")
        res.redirect("/admin/categorias")
    })
})


router.post("/categorias/deletar", eAdmin, (req, res) => {
    Categoria.deleteOne({_id: req.body.id}).then(() => {
        req.flash("success_msg", "Categoria deletada com sucesso")
        res.redirect("/admin/categorias")
    }).catch((err) => {
        req.flash("error_msg", "Houve um erro ao deletar a categoria")
        res.redirect("/admin/categorias")
    })
})

router.get("/postagens", eAdmin, (req, res) => {
    Postagem.find().populate("categoria").sort({data:"desc"}).then((postagens) => {
        res.render("admin/postagens", {postagens: postagens})
    }).catch((err) => {
        req.flash("error_msg", "Houve um erro ao listar as postagens")
        res.redirect("/admin")
    })
})

router.get("/postagens/add", eAdmin, (req, res) => {
    Categoria.find().then((categorias) => {
        res.render("admin/addpostagem", {categorias: categorias})
    }).catch((err) => {
        req.flash("error_msg", "Houve um erro ao carregar o formulário")
        res.redirect("/admin")
    })
})

router.post("/postagens/nova", eAdmin, (req, res) => {

    let erros = []

    if(req.body.categoria == "0"){
        erros.push({texto: "Categoria inválida, registre uma categoria"})
    }

    if(erros.length > 0){
        res.render("admin/addpostagem", {erros: erros})
    } else{
        const novaPostagem = {
            titulo: req.body.titulo,
            slug: req.body.slug,
            descricao: req.body.descricao,
            conteudo: req.body.conteudo,
            categoria: req.body.categoria
        }

        new Postagem(novaPostagem).save().then(() => {
            req.flash("success_msg", "Postagem criada com sucesso")
            res.redirect("/admin/postagens")
        }).catch((err) =>{
            req.flash("error_msg", "Houve um erro durante o salvamento da postagem")
            res.redirect("/admin/postagens")
        })
    }
})

router.get("/postagens/edit/:id", eAdmin, (req, res) => {
    Postagem.findOne({_id: req.params.id}).then((postagem) => {
        Categoria.find().then((categorias) => {
            res.render("admin/editpostagens", {categorias: categorias, postagem: postagem})
        }).catch((err) => {
            req.flash("error_msg", "Houve um erro ao listar as categorias")
            res.redirect("/admin/postagens")
        })
    }).catch((err) => {
        req.flash("error_msg", "Houve um erro ao carregar o formulário de edição")
        res.redirect("/admin/postagens")
    })
})

router.post("/postagens/edit", eAdmin, (req, res) => {
    Postagem.findOne({_id: req.body.id}).then((postagem) => {
        postagem.titulo = req.body.titulo,
        postagem.slug = req.body.slug,
        postagem.descricao = req.body.descricao,
        postagem.conteudo = req.body.conteudo,
        postagem.categoria = req.body.categoria

        postagem.save().then(() => {
            req.flash("success_msg", "Postagem editada com sucesso")
            res.redirect("/admin/postagens")
        }).catch((err) => {
            res.flash("error_msg", "Houve interno")
            res.redirect("/admin/postagens")
        })
    }).catch((err) => {
        req.flash("error_msg", "Houve um erro ao salvar a edição")
        res.redirect("/admin/postagens")
    })
})

router.get("/postagens/deletar/:id", eAdmin, (req, res) => {
    Postagem.deleteOne({_id: req.params.id}).then(() => {
        req.flash("success_msg", "Postagem deletada com sucesso")
        res.redirect("/admin/postagens")
    }).catch((err) => {
        req.flash("error_msg", "Houve um erro interno")
        res.redirect("/admin/postagens")
    })
})
export default router;
