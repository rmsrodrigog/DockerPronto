<?php
    $portais = [
        'siga'=>'SIGA',
        'estudantes'=>'Estudantes',
        'selecao'=>'Seleção',
        'polos'=>'Polos',
        'servicos'=>'Serviços',
        'api'=>'API',
    ];
    $ies = [
        'bsp'=>[
            'image'=>'https://loja.bsponline.com.br/media/logo/websites/22/bsp.png',
            'color'=>'#1b2c5d',
        ],
        'fad'=>[
            'image'=>'https://loja.fadergsonline.com.br/media/logo/websites/10/fadergs.png',
            'color'=>'#c9252c',
        ],
        'fpb'=>[
            'image'=>'https://loja.fpbonline.com.br/static/version1591150115/frontend/Webjump/theme-frontend-laureate-fpb/pt_BR/images/logo.svg',
            'color'=>'#0a548b',
        ],
        'fmu'=>[
            'image'=>'https://loja.fmuonline.com.br/media/logo/websites/13/fmu.png',
            'color'=>'#d41f26',
        ],
        'ibm'=>[
            'image'=>'https://loja.ibmronline.com.br/static/version1591150115/frontend/Webjump/theme-frontend-laureate-ibmr/pt_BR/images/logo.svg',
            'color'=>'#157945',
        ],
        'uam'=>[
            'image'=>'https://loja.anhembionline.com.br/media/logo/websites/7/uam.png',
            'color'=>'#00ae8e',
        ],
        'ufg'=>[
            'image'=>'https://loja.unifgonline.com.br/static/version1591150115/frontend/Webjump/theme-frontend-laureate-unifg/pt_BR/images/logo.svg',
            'color'=>'#ec8310',
        ],
        'unf'=>[
            'image'=>'https://loja.unifacsonline.com.br/media/logo/websites/16/unifacs.png',
            'color'=>'#005281',
        ],
        'unp'=>[
            'image'=>'https://loja.unponline.com.br/media/logo/websites/19/unp.png',
            'color'=>'#005baa',
        ],
        'unr'=>[
            'image'=>'https://loja.uniritteronline.com.br/static/version1591150115/frontend/Webjump/theme-frontend-laureate-uniritter/pt_BR/images/logo.svg',
            'color'=>'#dd2b27',
        ],
    ];
?>

<!DOCTYPE html>
<html lang="pt-BR">
    <head>
        <meta charset="utf-8">
        <title>DOCKER SIGA - Escolha do portal</title>
        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
        <style>
            body{
                background-color: #F6F6F6;
            }
            main {
                padding: 20px 0;
            }
            .card-img-top {
                height: 70px;
                width: 100%;
            }
            .cards{
                min-width: 264px
            }
            .list-group-item {
                padding: 4px 8px;
            }
            <?php
                foreach($ies as $ie => $ie_info){
            ?>
                .<?= $ie; ?> .card-img-top {
                    background: url(<?= $ie_info['image']; ?>);
                    background-position: center center;
                    background-repeat: no-repeat;
                    background-size: 200px auto;                          
                    border-bottom: <?= $ie_info['color']; ?> solid 3px;
                }
                .<?= $ie; ?> .btn-outline-secondary:hover,
                .<?= $ie; ?> .btn-outline-secondary:active,
                .<?= $ie; ?> .btn-outline-secondary:focus
                {
                    background-color: <?= $ie_info['color']; ?> !important;
                    box-shadow:none;
                }

                .<?= $ie; ?> small {
                    color: <?= $ie_info['color']; ?> !important;
                    font-weight: bold;
                }
            <?php
                }
            ?>
        </style>
    </head>
    <body>
        <main>
            <div class="container-fluid">
                <div class="row">
                    <?php
                        foreach($ies as $ie => $ie_info){
                    ?>
                        <div class="col-sm-12 col-lg-2 cards <?= $ie; ?>">
                            <div class="card mb-4 shadow-sm">
                                <div class="card-img-top"></div>
                                <ul class="list-group list-group-flush">
                                    <?php
                                        foreach($portais as $portal => $nome_portal){
                                    ?>
                                        <li class="list-group-item">
                                            <div class="d-flex justify-content-between align-items-center">                                        
                                                <small class="text-muted"><?= $nome_portal; ?></small>
                                                <div class="btn-group">
                                                    <a href="http://<?= $portal; ?>.<?= $ie; ?>.localhost/" target="_blank" role="button" class="btn btn-sm btn-outline-secondary">Dev</a>
                                                    <a href="http://<?= $portal; ?>.<?= $ie; ?>-fun.localhost/" target="_blank" role="button" class="btn btn-sm btn-outline-secondary">Funcional</a>
                                                </div>
                                            </div>
                                        </li>
                                    <?php
                                        }
                                    ?>
                                </ul>
                            </div>
                        </div>
                    <?php
                        }
                    ?>
                </div>
            </div>
        </main>
    </body>
</html>
