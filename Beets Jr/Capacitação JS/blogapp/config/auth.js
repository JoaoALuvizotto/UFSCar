import { Strategy as LocalStrategy } from "passport-local";
import mongoose from 'mongoose';
import bcrypt from  'bcryptjs'

require("../models/Usuario")
const Usuario = mongoose.model("usuarios")

module.exports = function(passport){
    //O campo que será analisado aqui será o email
    passport.use(new LocalStrategy({usernameField: 'email', passwordField:"senha"}, (email, senha, done) => {
        Usuario.findOne({email:email}).then((usuario) => {
            if(!usuario){
                //pra que serve a função done? 
                return done(null, false, {message: "Esta conta não existe"})
            }
            //Comparando as senhas encriptadas 
            bcrypt.compare(senha, usuario.senha, (erro, batem) => {
                if(batem){
                    return done(null, usuario)
                }
                else
                {
                    return done(null, false, {message: "Senha incorreta"})
                }
            })



        })
    }))

    //Salvar os dados do Usuário em uma sessão
    passport.serializeUser((usuario, done) => {
        done(null, usuario.id)
    })

    passport.deserializeUser((id, done) => {
        Usuario.findById(id, (err, usuario) => {
            done(err, usuario)
        })
    })
}
