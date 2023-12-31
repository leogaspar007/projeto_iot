const char pagina[] = R"=====(<!DOCTYPE html>
<html lang="pt-BR">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>iot_semb2</title>

    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@300&display=swap" rel="stylesheet">

    <style>

        *{
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Roboto', sans-serif;
        }
        body{
            background-color: #dfdfdf;
        }

        header{
            width: 100%;
            background-color: #1c1e26;
            display: flex;
            align-items: center;
        }

        header .logo img{
            width: 100%;
            max-width: 300px;  
        }

        header .title{
            color: white;
            font-size: 20px;
        }
                
        .container{
            width: 100%;
            max-width: 1300px;
            margin: 0 auto;
            display: flex;
        }

        section{
            background-color: #1c1e26;
            padding: 10px;
        }

        section .item-head{
            display: flex;
            justify-content: space-between;
            align-items: center;
        }

        section .titulo{
            color:white;
            font-weight: 20px;
        }

        section .estado{
            font-size: 13px;
            padding: 3px;
            text-transform: uppercase;
        }

        .on{
            background-color: rgb(0, 255, 0);
            color: black;
        }
        .off{
            background-color: red;
            color: white;  
        }

        section .acoes {
            width: 100%;
            padding-top: 20px;
            display: flex;
            justify-content: space-between;
        }

        section .acoes .ligar {
            width: 50%;
            height: 40px;
            background-color: #28a745;
            display: flex;
            justify-content: center;
            align-items: center;
            text-decoration: none;
            font-size: 15px;
            text-transform: uppercase;
            color: white;
            margin-right: 10px;
            transition: all 0.2s;
        }

        section .acoes .ligar:hover{
            background-color: green;
        }

        section .acoes .desligar{
            width: 50%;
            height: 40px;
            background-color: red;
            display: flex;
            justify-content: center;
            align-items: center;
            text-decoration: none;
            font-size: 15px;
            text-transform: uppercase;
            color: white;
            transition: all 0.2s;
        }

        section .acoes .desligar:hover{
            background-color: rgb(196, 21, 21);
        }

        section .acoes .leitura{
            background-color: white;
            width: 100%;
            height: 40px;
            line-height: 40px;
            vertical-align: middle;
            text-align: center;
            font-size: 20px;
        }

        /*quando for pc*/
        @media (min-width: 700px){
            header{
                justify-content: space-between;
                padding: 20px 60px 20px 60px;
            }
            .container {
                justify-content: center;
                padding: 20px 40px 20px 40px;
                flex-wrap: wrap;
            }
            section{
                width: 30%;
                margin: 20px;
            }
        }
       
        
        /*quando for mobile*/
        @media (max-width: 700px){
            header{
                justify-content: center;
                flex-direction: column;
                align-items: center;
                padding: 30px 10px 20px 10px;
                
            }

            header .title {
            margin-top: 10px;
            }

            .container{
                padding: 20px;
                flex-direction: column;
                gap: 18px;
            }

            section{

                width: 100%;
                margin: 1px;
            }

        }

    </style>

</head>
<body>
    <header>
        <div class="logo">
            <img src="https://uploaddeimagens.com.br/images/004/300/053/original/logo1.png?1673820095" alt="smart home">
        </div>
        <div class="title">IOT with esp8266</div>
    </header>

    <div class="container">
)=====";

const char rodape[] = R"=====(</div>

    <footer>
  
    </footer>
</body>

</html>)=====";
