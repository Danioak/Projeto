usando  Sistema ;

espaço de nomes  DIO . Series
{
     programa de aula
    {
        static  SerieRepositorio  repositorio  =  new  SerieRepositorio ();
        static  void  Main ( string [] args )
        {
            string  opcaoUsuario  =  ObterOpcaoUsuario ();

			while ( opcaoUsuario.ToUpper ( ) ! =  " X " )
			{
				switch ( opcaoUsuario )
				{
					caso  " 1 " :
						ListarSeries ();
						quebrar ;
					caso  " 2 " :
						Série Inserção ();
						quebrar ;
					caso  " 3 " :
						AtualizarSérie ();
						quebrar ;
					caso  " 4 " :
						ExcluirSérie ();
						quebrar ;
					caso  " 5 " :
						VisualizarSérie ();
						quebrar ;
					caso  " C " :
						Consola . Limpar ();
						quebrar ;

					padrão :
						lançar  novo  ArgumentOutOfRangeException ();
				}

				opcaoUsuario  =  ObterOpcaoUsuario ();
			}

			Consola . WriteLine ( " Obrigado por usar nossos serviços. " );
			Consola . ReadLinha ();
        }

        private  static  void  ExcluirSerie ()
		{
			Consola . Write ( " Digite o id da série: " );
			int  índiceSérie  =  int . Analisar ( Console . ReadLine ());

			repositório . Exclui ( indiceSerie );
		}

        private  static  void  VisualizarSérie ()
		{
			Consola . Write ( " Digite o id da série: " );
			int  índiceSérie  =  int . Analisar ( Console . ReadLine ());

			var  serie  =  repositorio . RetornaPorId ( indiceSerie );

			Consola . WriteLine ( série );
		}

         vazio estático  privado AtualizarSerie () 
		{
			Consola . Write ( " Digite o id da série: " );
			int  índiceSérie  =  int . Analisar ( Console . ReadLine ());


			foreach ( int  i  in  Enum . GetValues ( typeof ( Genero )))
			{
				Consola . WriteLine ( " {0}-{1} " , i , Enum . GetName ( typeof ( Genero ), i ));
			}
			Consola . Write ( " Digite o gênero entre as opções acima: " );
			int  entradaGenero  =  int . Analisar ( Console . ReadLine ());

			Consola . Write ( " Digite o Título da Série: " );
			string  entradaTitulo  =  Console . ReadLinha ();

			Consola . Write ( " Digite o Ano de Início da Série: " );
			int  entradaAno  =  int . Analisar ( Console . ReadLine ());

			Consola . Write ( " Digite a Descrição da Série: " );
			string  entradaDescricao  =  Console . ReadLinha ();

			Serie  atualizaSerie  =  new  Serie ( id : indiceSerie ,
										genero : ( Genero ) entradaGenero ,
										titulo : entradaTitulo ,
										ano : entradaAno ,
										descricao : entradaDescricao );

			repositório . Atualiza ( indiceSerie , atualizaSerie );
		}
        private  static  void  ListarSeries ()
		{
			Consola . WriteLine ( " Lista de séries " );

			var  lista  =  repositório . Lista ();

			if ( lista . Count  ==  0 )
			{
				Consola . WriteLine ( " Nenhuma série cadastrada. " );
				retorno ;
			}

			foreach ( série var  na lista )  
			{
                var  excluido  =  serie . retornaExcluido ();
                
				Consola . WriteLine ( " #ID {0}: - {1} {2} " , serie . retornaId (), serie . retornaTitulo (), ( excluido  ?  " *Excluído* "  :  " " ));
			}
		}

        privado  estático  void  InserirSerie ()
		{
			Consola . WriteLine ( " Inserir nova série " );

			foreach ( int  i  in  Enum . GetValues ( typeof ( Genero )))
			{
				Consola . WriteLine ( " {0}-{1} " , i , Enum . GetName ( typeof ( Genero ), i ));
			}
			Consola . Write ( " Digite o gênero entre as opções acima: " );
			int  entradaGenero  =  int . Analisar ( Console . ReadLine ());

			Consola . Write ( " Digite o Título da Série: " );
			string  entradaTitulo  =  Console . ReadLinha ();

			Consola . Write ( " Digite o Ano de Início da Série: " );
			int  entradaAno  =  int . Analisar ( Console . ReadLine ());

			Consola . Write ( " Digite a Descrição da Série: " );
			string  entradaDescricao  =  Console . ReadLinha ();

			Serie  novaSerie  =  new  Serie ( id : repositorio . ProximoId (),
										genero : ( Genero ) entradaGenero ,
										titulo : entradaTitulo ,
										ano : entradaAno ,
										descricao : entradaDescricao );

			repositório . Insere ( novaSerie );
		}

         string estática  privada ObterOpcaoUsuario () 
		{
			Consola . EscreverLinha ();
			Consola . WriteLine ( " DIO Séries a seu divertimento!!! " );
			Consola . WriteLine ( " Informe a opção desejada: " );

			Consola . WriteLine ( " 1- Listar séries " );
			Consola . WriteLine ( " 2- inserir nova série " );
			Consola . WriteLine ( " 3- Atualizar série " );
			Consola . WriteLine ( " 4- Excluir série " );
			Consola . WriteLine ( " 5- Visualizar série " );
			Consola . WriteLine ( " C- Limpar Tela " );
			Consola . WriteLine ( " X-Sair " );
			Consola . EscreverLinha ();

			string  opcaoUsuario  =  Console . LeiaLinha (). Superior ();
			Consola . EscreverLinha ();
			return  opcaoUsuario ;
		}
    }
}