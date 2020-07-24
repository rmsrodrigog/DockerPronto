<?php
//error_reporting(E_ALL & ~E_STRICT & ~E_DEPRECATED & ~E_NOTICE);
define("UTILIZA_NOVO_DECORADOR", true);
set_include_path(get_include_path() . PATH_SEPARATOR . '/opt/config/' . PATH_SEPARATOR . '/opt/www/phpclasses'. PATH_SEPARATOR . '/usr/share/pear');

GLOBAL $SISCONF;
GLOBAL $TNS_SUN;
GLOBAL $LOCAL_PATH;

GLOBAL $CONEXAO_PADRAO;
GLOBAL $listaDesenvolvedores;
GLOBAL $urlAcessada;

$SISCONF['ENVIRONMENT'] = 'DEV';
$SISCONF['WS']['SECRET'] = '123456';

$ipsDesenvolvedores = [
    "10.10.10.8",
    "10.10.10.7",
    "10.10.10.11",
    "10.10.10.15",
    "10.10.10.5",
    "10.10.10.7",
    "192.168.1.6",
    "10.11.10.29",
    "10.1.1.120",
    "10.1.1.189",
    "10.1.1.171",
    "10.1.1.248"
];

$testeMatricula = [
    "10.10.5.29",
    "10.10.5.9",
    "10.10.11.2",
    "10.10.5.52",
    "10.10.5.8",
    "10.10.11.8"
];

$CONEXAO_PADRAO['HOST']     = 'guarita';
$CONEXAO_PADRAO['BASE']     = 'siga_eadfmu_funcional';
$CONEXAO_PADRAO['SID']      = 'siga_eadfmu_funcional';
$SISCONF['SIS']['AMBIENTE'] = 'EAD';

$urlAcessada = $_SERVER['PHP_SELF'];
ini_set('memory_limit', '512M');
$listaDesenvolvedores[] = 'joao.zwetsch';
$listaDesenvolvedores[] = 'sistemas';
$listaDesenvolvedores[] = 'jeison_chollet';
$listaDesenvolvedores[] = 'rafael.pires';

function ehUrlDesenvolvedor()
{
    if ($_SERVER['HTTP_HOST'] == 'ws.uniritter.edu.br') {
        return "juliano_cezaro";
    }
    GLOBAL $urlAcessada;
    //print $urlAcessada;
    GLOBAL $listaDesenvolvedores;
    foreach ($listaDesenvolvedores as $idLinha => $desenvolvedor) {
        if (strpos($urlAcessada, $desenvolvedor)) {
            return $desenvolvedor;
        }
    }
    return null;
}

$desenvolvedor = ehUrlDesenvolvedor();

/**
 * Definindo variáveis que poderão ser alteradas pelo desenvolvedor
 */
$LOCAL_PATH['TURKEY']['CLASSES']  = "/opt/www/phpclasses";
$LOCAL_PATH['TURKEY']['WEB_ROOT'] = "/opt/www/siga/";

$LOCAL_PATH['PROFESSORES']['CLASSES']  = "/opt/www/phpclasses";
$LOCAL_PATH['PROFESSORES']['WEB_ROOT'] = "/opt/www/portal/professores";

$LOCAL_PATH['ALUNOS']['CLASSES']  = "/opt/www/phpclasses";
$LOCAL_PATH['ALUNOS']['WEB_ROOT'] = "/opt/www/portal/academicos";

// localizacao do framework
$SISCONF['SIS']['FRAME']['PATH'] = "/opt/www/phpclasses/";

// localizacao do site e elementos internos
#$SISCONF['SIS']['COMUM']['HOST']  = "http://siga2.uniritter.edu.br";
$SISCONF['SIS']['COMUM']['HOST']         = "http://siga.fapa.com.br";
$SISCONF['SIS']['COMUM']['TEMAS']        = $SISCONF['SIS']['COMUM']['HOST'] . "/temas/";
$SISCONF['SIS']['COMUM']['IMAGENS']      = $SISCONF['SIS']['COMUM']['HOST'] . "/imagens/";
$SISCONF['SIS']['COMUM']['IMAGENS_TEMA'] = $SISCONF['SIS']['COMUM']['HOST'] . "/temas/comum/images/";

/*Configurações de caminho do sistem academico*/
$SISCONF['PATH_WEB']['TURKEY']['ROOT']              = "/";
$SISCONF['PATH_WEB']['TURKEY']['LAYOUT']['DEFAULT'] = $SISCONF['PATH_WEB']['TURKEY']['ROOT'] . "layout/default/";

$SISCONF['PATH_SCRIPT']['DEFAULT']      = $SISCONF['PATH_WEB']['TURKEY']['ROOT'] . "jscripts";
$SISCONF['PATH_SCRIPT']['TURKEY']       = $SISCONF['PATH_WEB']['TURKEY']['ROOT'] . "jscripts/";
$SISCONF['AJAX']['TURKEY']['PROG_PATH'] = $SISCONF['PATH_WEB']['TURKEY']['ROOT'] . "ajax/";

//Configuração de caminha para biblioteca jQuery
$SISCONF['JQUERY'] = $SISCONF['PATH_SCRIPT']['TURKEY'] . "jquery/";

//Configuração de caminho para biblioteca TinyMCE
$SISCONF['TINYMCE'] = $SISCONF['PATH_SCRIPT']['TURKEY'] . "tinymce/jscripts/tiny_mce/tiny_mce.js";

$SISCONF['SIS']['TURKEY']['HOST'] = $SISCONF['SIS']['COMUM']['HOST'] . $SISCONF['PATH_WEB']['TURKEY']['ROOT'];

GLOBAL $__LOCAL_CONTEUDO_AJUDA;
$__LOCAL_CONTEUDO_AJUDA = $LOCAL_PATH['TURKEY']['WEB_ROOT'] . "layout/default/img/ajuda/";
GLOBAL $__WEB_CONTEUDO_AJUDA;
$__WEB_CONTEUDO_AJUDA = $SISCONF['PATH_WEB']['TURKEY']['LAYOUT']['DEFAULT'] . "img/ajuda/";

GLOBAL $__LOCAL_JWPLAYER;
$__LOCAL_JWPLAYER = $LOCAL_PATH['TURKEY']['WEB_ROOT'] . "jscripts/jwplayer/";
GLOBAL $__WEB_JWPLAYER;
$__WEB_JWPLAYER = $SISCONF['PATH_WEB']['TURKEY']['ROOT'] . "jscripts/jwplayer/";

//seção de configuração do sistema na Intranet
#$SISCONF['SIS']['INTRANET']['PATH']  = "/opt/sites/uniritter/phpclasses/";
#$SISCONF['SIS']['INTRANET']['THEMA']['PATH']  = "/opt/sites/uniritter/siga/temas/default/";
#$SISCONF['SIS']['INTRANET']['PROGRAMA']  = "/opt/sites/uniritter/siga/modulos/";
#$SISCONF['SIS']['INTRANET']['HOST']  = "http://turkey.uniritter.edu.br";
//$SISCONF['SIS']['INTRANET']['NEGOCIO'] = $SISCONF['SIS']['INTRANET']['PATH']."negocio/";
//$SISCONF['SIS']['INTRANET']['INTERFACE']  = $SISCONF['SIS']['INTRANET']['PATH']."interface/";
//$SISCONF['SIS']['INTRANET']['NEGOCIO']['COMUM'] = $SISCONF['SIS']['INTRANET']['NEGOCIO']."comum/";
#$SISCONF['SIS']['INTRANET']['NEGOCIO']['COMUM'] = $SISCONF['SIS']['INTRANET']['PATH']."negocio/"."comum/";
//$SISCONF['SIS']['INTRANET']['INTERFACE']['COMUM'] = $SISCONF['SIS']['INTRANET']['INTERFACE']."comum/";
#$SISCONF['SIS']['INTRANET']['INTERFACE']['COMUM'] = $SISCONF['SIS']['INTRANET']['PATH']."interface/"."comum/";
#$SISCONF['SIS']['INTRANET']['THEMA']['HOST']  = $SISCONF['SIS']['INTRANET']['HOST']."/siga/temas/";

$SISCONF['SIS']['BASE'] = "/opt/www/siga/";
$SISCONF['SIS']['HOST'] = "/opt/www/siga";

$SISCONF['ARQUIVOS']['INTERNO']['PATH']['LOCAL'] = "/opt/dados/arquivos/";
$SISCONF['ARQUIVOS']['EXTERNO']['PATH']['LOCAL'] = "/opt/dados/arquivos_web/";
$SISCONF['ARQUIVOS']['EXTERNO']['PATH']['WEB']   = $SISCONF['SIS']['COMUM']['HOST'] . "/arquivos_web/";
$SISCONF['ARQUIVOS']['REGISTRO_PONTO']           = $SISCONF['ARQUIVOS']['INTERNO']['PATH']['LOCAL'] . "gestao_recursos/registro_ponto/";

$SISCONF['SIS']['PROFESSORES']['HOST']                               = "https://professores2.uniritter.edu.br";
$SISCONF['PATH_WEB']['PROFESSORES']['ROOT']                          = "/";
$SISCONF['SIS']['PROFESSORES']['ARQUIVOS']['EXTERNO']['PATH']['WEB'] = $SISCONF['SIS']['PROFESSORES']['HOST'] . "/arquivos_web/";


$SISCONF['SIS']['ALUNOS']['HOST'] = "http://academicos.fapa.com.br";
$SISCONF['PATH_WEB']['ALUNOS']['ROOT']                 = "/";
$SISCONF['SIS']['ALUNOS']['ARQUIVOS']['PATH']['LOCAL'] = "/opt/dados/arquivos_web/";
$SISCONF['SIS']['ALUNOS']['ARQUIVOS']['PATH']['WEB']   = $SISCONF['SIS']['ALUNOS']['HOST'] . "/arquivos_web/";

$SISCONF['SIS']['VESTIBULAR']['HOST']      = "http://selecao.fmu.localhost";
$SISCONF['PATH_WEB']['VESTIBULAR']['ROOT'] = "/";


$SISCONF['SIS']['SERVICOS']['HOST']      = "https://servicos2.uniritter.edu.br/";
$SISCONF['PATH_WEB']['SERVICOS']['ROOT'] = "/";

$SISCONF['PATH_WEB']['SERVICOS']['ROOT']              = $SISCONF['SIS']['SERVICOS']['HOST'];
$SISCONF['PATH_WEB']['SERVICOS']['LAYOUT']['DEFAULT'] = $SISCONF['SIS']['SERVICOS']['HOST'] . "/layout/default/";
$SISCONF['PATH_SCRIPT']['SERVICOS']                   = $SISCONF['SIS']['SERVICOS']['HOST'] . "/jscripts/";


/*-----------------------------------------------------------------------------------------*/

/*--------------------- Configurações relacionadas ao envio de email ---------------------*/
/*
$SISCONF['SIS']['EMAIL']['TIPO'] = 'SMTP';
$SISCONF['SIS']['EMAIL']['AUTENTICADO'] = true;
$SISCONF['SIS']['EMAIL']['HOST'] = 'pod51028.outlook.com';
$SISCONF['SIS']['EMAIL']['PROTOCOLO'] = 'tls';
$SISCONF['SIS']['EMAIL']['PORTA'] = '587';
$SISCONF['SIS']['EMAIL']['USUARIO'] = 'siga@uniritter.edu.br';
$SISCONF['SIS']['EMAIL']['SENHA'] = 's1G*0925';
$SISCONF['SIS']['EMAIL']['FROM'] = 'siga@uniritter.edu.br';
*
*/
/*
$SISCONF['SIS']['EMAIL']['TIPO']        = 'SMTP';
$SISCONF['SIS']['EMAIL']['AUTENTICADO'] = true;
$SISCONF['SIS']['EMAIL']['HOST']        = 'smtp.office365.com';
$SISCONF['SIS']['EMAIL']['PROTOCOLO']   = 'tls';
$SISCONF['SIS']['EMAIL']['PORTA']       = '587';
$SISCONF['SIS']['EMAIL']['USUARIO']     = 'siga@eadlaureate.com.br';
$SISCONF['SIS']['EMAIL']['SENHA']       = 'Boka6500';
$SISCONF['SIS']['EMAIL']['FROM']        = 'siga@eadlaureate.com.br';
*/

/*
$SISCONF['SIS']['EMAIL']['TIPO']        = 'SMTP';
$SISCONF['SIS']['EMAIL']['AUTENTICADO'] = true;
$SISCONF['SIS']['EMAIL']['HOST']        = 'smtp.office365.com';
$SISCONF['SIS']['EMAIL']['PROTOCOLO']   = 'tls';
$SISCONF['SIS']['EMAIL']['PORTA']       = '587';
$SISCONF['SIS']['EMAIL']['USUARIO']     = 'fmuonline@ead.br';
$SISCONF['SIS']['EMAIL']['SENHA']       = '$7!m$XzjH3j7';
$SISCONF['SIS']['EMAIL']['FROM']        = 'fmuonline@ead.br';
*/

$SISCONF['SIS']['EMAIL']['TIPO']        = 'SMTP';
$SISCONF['SIS']['EMAIL']['AUTENTICADO'] = true;
$SISCONF['SIS']['EMAIL']['HOST']        = 'smtp.office365.com';
$SISCONF['SIS']['EMAIL']['PROTOCOLO']   = 'tls';
$SISCONF['SIS']['EMAIL']['PORTA']       = '587';
$SISCONF['SIS']['EMAIL']['USUARIO']     = 'siga@eadlaureate.com.br';
$SISCONF['SIS']['EMAIL']['SENHA']       = '$7!m$XzjH3j7';
$SISCONF['SIS']['EMAIL']['FROM']        = 'siga@eadlaureate.com.br';

/*$SISCONF['SIS']['EMAIL']['TIPO'] = 'SMTP';
$SISCONF['SIS']['EMAIL']['AUTENTICADO'] = true;
$SISCONF['SIS']['EMAIL']['HOST'] = 'pod51028.outlook.com';
$SISCONF['SIS']['EMAIL']['PROTOCOLO'] = 'tls';
$SISCONF['SIS']['EMAIL']['PORTA'] = '587';
$SISCONF['SIS']['EMAIL']['USUARIO'] = 'wellington_guedes@uniritter.edu.br';
$SISCONF['SIS']['EMAIL']['SENHA'] = 'Well2905@*';
$SISCONF['SIS']['EMAIL']['FROM'] = 'wellington_guedes@uniritter.edu.br';
*/
/*----------------------------------------------------------------------------------------*/
//if($_SERVER['REMOTE_ADDR'] == '10.11.10.8' && strpos($_SERVER['DOCUMENT_ROOT'], 'enviaEmailFluxoAprovacao_cron.php')){
//echo $_SERVER['REMOTE_ADDR'].PHP_EOL;

require_once '/opt/config/configUsuario.inc';


/*Configurações de caminho dos servicos*/
$SISCONF['PATH_WEB']['SERVICOS']['LAYOUT']['DEFAULT'] = $SISCONF['PATH_WEB']['SERVICOS']['ROOT'] . "layout/default/";
$SISCONF['PATH_SCRIPT']['SERVICOS']                   = $SISCONF['PATH_WEB']['SERVICOS']['ROOT'] . "jscripts/";
$SISCONF['AJAX']['SERVICOS']['JS_PATH']               = $SISCONF['PATH_SCRIPT']['SERVICOS'] . "ajax/";
$SISCONF['AJAX']['SERVICOS']['JS_HEADER']             = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['SERVICOS']['JS_PATH'] . "ajax.js \"></script>\n";
$SISCONF['AJAX']['SERVICOS']['PROG_PATH']             = $SISCONF['PATH_WEB']['SERVICOS']['ROOT'] . "ajax/";
$SISCONF['AJAX']['SERVICOS']['HEADER_LOGOFF']         = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['SERVICOS']['PROG_PATH'] . "sessao/logoff.js \"></script>\n";
$SISCONF['AJAX']['SERVICOS']['HEADER_MENU']           = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['SERVICOS']['PROG_PATH'] . "sessao/menu.js\" ></script>\n";
$SISCONF['AJAX']['SERVICOS']['HEADER_MENU_IE7']       = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['SERVICOS']['PROG_PATH'] . "sessao/menu_ie7.js\" ></script>\n";
$SISCONF['CONSISTENCIA']['JS_PATH_SERVICOS']          = $SISCONF['PATH_SCRIPT']['SERVICOS'] . "consistencia/";
/*fim*/

/**
 * Inicio Configurações de Eventos
 *
 */
$SISCONF['FORMULARIOS']['EVENTOS']['PATH_WEB']['ROOT'] = "/";

$SISCONF['SIS']['EVENTOS']['HOST']                   = $SISCONF['FORMULARIOS']['EVENTOS']['HOST'];
$SISCONF['PATH_WEB']['EVENTOS']['ROOT']              = $SISCONF['SIS']['EVENTOS']['HOST'];
$SISCONF['PATH_WEB']['EVENTOS']['LAYOUT']['DEFAULT'] = $SISCONF['SIS']['EVENTOS']['HOST'] . "/layout/default/";
$SISCONF['PATH_SCRIPT']['EVENTOS']                   = $SISCONF['SIS']['EVENTOS']['HOST'] . "/jscripts/";

/**
 * Fim Configurações de Eventos
 * a linha $SISCONF['SIS']['COMUM']['TKF_TEMPLATES']  = $SISCONF['SIS']['COMUM']['PATH']."tkfTemplates/"; deve ser adicionada no final deste arquivo
 *
 */

/**
 * ----------------------------------------------------------------------------
 */

$SISCONF['SIS']['COMUM']['MENSAGEM']['CONEXAO']  = '<BR>Por Favor, entre em contato <BR>pelo o Telefone (51) 32303338';
$SISCONF['SIS']['COMUM']['MENSAGEM']['SISTEMAS'] = 'Núcleo de Sistemas de Informação<BR>Ramal: 3338<BR>';
$SISCONF['SIS']['COMUM']['MENSAGEM']['CADASTRO'] = 'Entre em contato com o DTI';

$SISCONF['SIS']['NOME'] = "SIGA - Sistema Integrado de Gestão Acadêmica";


$SISCONF['SIS']['TITULO_PROFESSORES'] = "Portal dos Professores";
$SISCONF['SIS']['TITULO_ALUNOS']      = "Portal do Aluno";

$SISCONF['SIS']['COMERCIAL']['AMBIENTE'] = $SISCONF['SIS']['AMBIENTE'];
//$SISCONF['SIS']['COMERCIAL']['AMBIENTE'] = 'ESADE';

$SISCONF['LAUREATE']['ENCRIPT']['IV']                   = 'ShHhd8a08JhJiho98ayslcjh';
$SISCONF['LAUREATE']['ENCRIPT']['KEY']['UNIRITTER']     = 'Qminc8h72bgtino83vbngthd';
$SISCONF['LAUREATE']['ENCRIPT']['KEY']['ESADE']         = 'Zbenc3j60htguni39athmnbd';
$SISCONF['LAUREATE']['ENCRIPT']['ACRONYM']['UNIRITTER'] = 'UniRitter';
$SISCONF['LAUREATE']['ENCRIPT']['ACRONYM']['ESADE']     = 'FADERGS';

$SISCONF['MASTERSMX']['ENCRIPT']['APP_KEY']          = 'ShHhd8a08JhJiho98ayslcjh';
$SISCONF['MASTERSMX']['ENCRIPT']['KEY']['UNIRITTER'] = 'Qminc8h72bgtino83vbngthd';
$SISCONF['MASTERSMX']['ENCRIPT']['KEY']['ESADE']     = '';
$SISCONF['MASTERSMX']['ENCRIPT']['KEY']['IBMR']      = '';


$SISCONF['SIS']['VCTO_DOC']['CUSTOMIZAVEL'] = 'S';
$SISCONF['SIS']['VCTO_DOC']['DIAS']         = array(
    '05' => '05',
    '10' => '10',
    '15' => '15'
);

//Seção de confuguração dos usuários logados
$SISCONF['SESSAO']['USUARIO']['ID']      = $userid;
$SISCONF['SESSAO']['USUARIO']['USUARIO'] = $user;
$SISCONF['SESSAO']['USUARIO']['NOME']    = $usernome;
$SISCONF['SESSAO']['USUARIO']['SENHA']   = $pwd;
$SISCONF['SESSAO']['USUARIO']['TEMA']    = "DEFAULT";
$SISCONF['SESSAO']['USUARIO']['IP']      = getenv("REMOTE_ADDR");

$SISCONF['ARQUIVO']        = $PHP_SELF;
$SISCONF['PAGINA']['LINK'] = getenv("HTTP_REFERER");
$SISCONF['PAGINA']['VARS'] = '';

//seções de configuração estrutura lógica da arquitetura do sistema

//METRICS_ACTIVE = Se true ativa cálculo de tempo de criação no serv. e carga da página no browser
$SISCONF['SIS']['METRICS']['ACTIVE'] = false;

//seção de configuração dos Targets de programas.
$SISCONF['SIS']['TARGET']['MENU']     = " target=\"menu\" ";
$SISCONF['SIS']['TARGET']['PROGRAMA'] = " target=\"corpo\" ";

//seção de configuração do COMUM (DOM??NIOS)
$SISCONF['SIS']['COMUM']['DOMAIN']            = "http://www.uniritter.edu.br/";
$SISCONF['SIS']['COMUM']['DOMAIN_EMAIL']      = "@uniritter.edu.br";
#$SISCONF['SIS']['COMUM']['DOMAIN_ACAD'] = "https://turkey.uniritter.edu.br/";
#$SISCONF['SIS']['COMUM']['DOMAIN_PROF'] = "https://turkey.uniritter.edu.br/";
$SISCONF['SIS']['COMUM']['DOMAIN_INTRANET']   = "http://intranet.uniritter.edu.br/";
$SISCONF['SIS']['COMUM']['DOMAIN_BIBLIOTECA'] = "http://biblioteca.uniritter.edu.br";
#$SISCONF['SIS']['COMUM']['DOMAIN_VESTIBULAR'] = "http://turkey.uniritter.edu.br/";

//seção de configuração do COMUM (Informações Gerais)
$SISCONF['SIS']['COMUM']['POA_CGC']      = "87.248.522/0002-76";
$SISCONF['SIS']['COMUM']['POA_ENDERECO'] = "Orfanotrófio, 555 - Alto Teresópolis";

$SISCONF['SIS']['COMUM']['CAN_CGC']      = "87.248.522/0003-57";
$SISCONF['SIS']['COMUM']['CAN_ENDERECO'] = "Santos Dumont, 888 - Niterói";

$SISCONF['SIS']['COMUM']['SIS_ADMIN_EMAIL']          = "sistemas@uniritter.edu.br";
$SISCONF['SIS']['COMUM']['REDES_ADMIN_EMAIL']        = "redes@uniritter.edu.br";
$SISCONF['SIS']['COMUM']['EAD_VESTIBULAR_FROM_NAME'] = "EAD Laureate / FMU";


//relativas a localizacao do framework
$SISCONF['SIS']['CLASSES']['NEGOCIO']       = $SISCONF['SIS']['FRAME']['PATH'] . "negocio/";
$SISCONF['SIS']['CLASSES']['INTERFACE']     = $SISCONF['SIS']['FRAME']['PATH'] . "interface/";
$SISCONF['SIS']['CLASSES']['PROCESSAMENTO'] = $SISCONF['SIS']['FRAME']['PATH'] . "processamento/";
$SISCONF['SIS']['CLASSES']['RELATORIO']     = $SISCONF['SIS']['FRAME']['PATH'] . "relatorio/";
$SISCONF['SIS']['CLASSES']['TABELA']        = $SISCONF['SIS']['FRAME']['PATH'] . "tabela/";

$SISCONF['SIS']['COMUM']['PATH']                       = $SISCONF['SIS']['FRAME']['PATH'] . "comum/";
$SISCONF['SIS']['COMUM']['SESSAO']                     = $SISCONF['SIS']['COMUM']['PATH'] . "sessao/";
$SISCONF['SIS']['COMUM']['BANCO']                      = $SISCONF['SIS']['COMUM']['PATH'] . "banco/";
$SISCONF['SIS']['COMUM']['TELA']                       = $SISCONF['SIS']['COMUM']['PATH'] . "tela/";
$SISCONF['SIS']['COMUM']['UTIL']                       = $SISCONF['SIS']['COMUM']['PATH'] . "util/";
$SISCONF['SIS']['COMUM']['ERRO']                       = $SISCONF['SIS']['COMUM']['PATH'] . "erro/";
$SISCONF['SIS']['COMUM']['PDF']                        = $SISCONF['SIS']['COMUM']['PATH'] . "pdf/";
$SISCONF['SIS']['COMUM']['XLS']                        = $SISCONF['SIS']['COMUM']['PATH'] . "xls/";
$SISCONF['SIS']['COMUM']['INCLUDES']                   = $SISCONF['SIS']['COMUM']['PATH'] . "incs/";
$SISCONF['SIS']['COMUM']['PERIFERICOS']['IMPRESSORAS'] = $SISCONF['SIS']['COMUM']['PATH'] . "perifericos/impressoras/";

$SISCONF['AJAX']['TURKEY']['JS_PATH']       = $SISCONF['PATH_SCRIPT']['TURKEY'] . "ajax/";
$SISCONF['AJAX']['TURKEY']['JS_HEADER']     = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['TURKEY']['JS_PATH'] . "ajax.js\"></script>\n";
$SISCONF['AJAX']['TURKEY']['HEADER_LOGOFF'] = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['TURKEY']['PROG_PATH'] . "sessao/logoff.js\"></script>\n";
$SISCONF['AJAX']['TURKEY']['HEADER_MENU']   = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['TURKEY']['PROG_PATH'] . "sessao/menu.js\"></script>\n";

/*fim*/

/*Configurações de caminho dos professores*/
$SISCONF['PATH_WEB']['PROFESSORES']['LAYOUT']['DEFAULT'] = $SISCONF['PATH_WEB']['PROFESSORES']['ROOT'] . "layout/default/";
$SISCONF['PATH_SCRIPT']['PROFESSORES']                   = $SISCONF['PATH_WEB']['PROFESSORES']['ROOT'] . "jscripts/";
$SISCONF['AJAX']['PROFESSORES']['JS_PATH']               = $SISCONF['PATH_SCRIPT']['PROFESSORES'] . "ajax/";
$SISCONF['AJAX']['PROFESSORES']['JS_HEADER']             = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['PROFESSORES']['JS_PATH'] . "ajax.js\"></script>\n";
$SISCONF['AJAX']['PROFESSORES']['PROG_PATH']             = $SISCONF['PATH_WEB']['PROFESSORES']['ROOT'] . "ajax/";
$SISCONF['AJAX']['PROFESSORES']['HEADER_LOGOFF']         = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['PROFESSORES']['PROG_PATH'] . "sessao/logoff.js\"></script>\n";
$SISCONF['AJAX']['PROFESSORES']['HEADER_MENU']           = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['PROFESSORES']['PROG_PATH'] . "sessao/menu.js\"></script>\n";
/*fim*/

/*Configurações de caminho dos alunos*/
//if($_SERVER['REMOTE_ADDR'] == '10.10.10.8'){
if (UTILIZA_NOVO_DECORADOR) {
    $SISCONF['PATH_WEB']['ALUNOS']['LAYOUT']['DEFAULT'] = $SISCONF['PATH_WEB']['ALUNOS']['ROOT'] . "layout/default/";
} else {
    $SISCONF['PATH_WEB']['ALUNOS']['LAYOUT']['DEFAULT'] = $SISCONF['PATH_WEB']['ALUNOS']['ROOT'] . "layout/old/";
}
//}else {
//	$SISCONF['PATH_WEB']['ALUNOS']['LAYOUT']['DEFAULT'] = $SISCONF['PATH_WEB']['ALUNOS']['ROOT']."layout/default/";
//}
$SISCONF['PATH_SCRIPT']['ALUNOS']           = $SISCONF['PATH_WEB']['ALUNOS']['ROOT'] . "jscripts/";
$SISCONF['AJAX']['ALUNOS']['JS_PATH']       = $SISCONF['PATH_SCRIPT']['ALUNOS'] . "ajax/";
$SISCONF['AJAX']['ALUNOS']['JS_HEADER']     = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['ALUNOS']['JS_PATH'] . "ajax.js\"></script>\n";
$SISCONF['AJAX']['ALUNOS']['PROG_PATH']     = $SISCONF['PATH_WEB']['ALUNOS']['ROOT'] . "ajax/";
$SISCONF['AJAX']['ALUNOS']['HEADER_LOGOFF'] = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['ALUNOS']['PROG_PATH'] . "sessao/logoff.js\"></script>\n";
$SISCONF['AJAX']['ALUNOS']['HEADER_MENU']   = "<script type=\"text/javascript\" src=\"" . $SISCONF['AJAX']['ALUNOS']['PROG_PATH'] . "sessao/menu.js\"></script>\n";
/*fim*/

$SISCONF['CONSISTENCIA']['JS_PATH'] = $SISCONF['PATH_SCRIPT']['DEFAULT'] . "/consistencia/";

$SISCONF['SIS']['PATH_SIGA']                   = "/siga";
$SISCONF['SIS']['FOTOS_SIGA']                  = $SISCONF['SIS']['PATH_SIGA'] . "/temp/";
$SISCONF['SIS']['PATH_IMAGENS']                = $SISCONF['SIS']['HOST'] . $SISCONF['SIS']['PATH_SIGA'] . "/imagens/";
$SISCONF['SIS']['PATH_IMG_CAB_PADRAO']         = $SISCONF['SIS']['HOST'] . "/temas/imagens/";
$SISCONF['SIS']['PATH_ARQ_COBRANCA_RETORNO']   = $SISCONF['SIS']['HOST'] . $SISCONF['SIS']['PATH_SIGA'] . "/modulos/financeiro/retorno/";
$SISCONF['SIS']['PATH_ARQ_COBRANCA_REMESSA']   = $SISCONF['SIS']['HOST'] . $SISCONF['SIS']['PATH_SIGA'] . "/modulos/financeiro/remessa/";
$SISCONF['SIS']['PATH_ARQ_LEITORA_VESTIBULAR'] = $SISCONF['SIS']['HOST'] . $SISCONF['SIS']['PATH_SIGA'] . "/modulos/vestibular/leitora/";

//Seção de configuração de bancos de dados -- ALIASES --
$SISCONF['DB']['DEFAULT'] = 'DESENV';

$SISCONF['DB']['AGENDAMENTO_UNIRITTER']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['AGENDAMENTO_UNIRITTER']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['AGENDAMENTO_UNIRITTER']['USUARIO']      = 'sistemas';
//$SISCONF['DB']['AGENDAMENTO_UNIRITTER']['SENHA'] = '3xz@?0ta';
$SISCONF['DB']['AGENDAMENTO_UNIRITTER']['SENHA']        = '123456';
$SISCONF['DB']['AGENDAMENTO_UNIRITTER']['HOST']         = "imbe";
$SISCONF['DB']['AGENDAMENTO_UNIRITTER']['SID']          = "agendamento_uniritter";
$SISCONF['DB']['AGENDAMENTO_UNIRITTER']['BASE']         = "agendamento_uniritter";
$SISCONF['DB']['AGENDAMENTO_UNIRITTER']['LOGA_BD']      = true;

$SISCONF['DB']['AGENDAMENTO_ESADE']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['AGENDAMENTO_ESADE']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['AGENDAMENTO_ESADE']['USUARIO']      = 'sistemas';
$SISCONF['DB']['AGENDAMENTO_ESADE']['SENHA']        = '3xz@?0ta';
$SISCONF['DB']['AGENDAMENTO_ESADE']['HOST']         = "imbe";
$SISCONF['DB']['AGENDAMENTO_ESADE']['SID']          = "agendamento_esade";
$SISCONF['DB']['AGENDAMENTO_ESADE']['BASE']         = "agendamento_esade";
$SISCONF['DB']['AGENDAMENTO_ESADE']['LOGA_BD']      = true;

$SISCONF['DB']['MOBILE']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['MOBILE']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['MOBILE']['USUARIO']      = 'sistemas';
$SISCONF['DB']['MOBILE']['SENHA']        = '3xz@?0ta';
$SISCONF['DB']['MOBILE']['HOST']         = "imbe";
$SISCONF['DB']['MOBILE']['SID']          = "siga_05062012";
$SISCONF['DB']['MOBILE']['BASE']         = "siga_05062012";
$SISCONF['DB']['MOBILE']['LOGA_BD']      = true;

//Configurações do BD da FADERGS para Migração de contato comercial
$SISCONF['DB']['COPIA_PROGRAMA']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['COPIA_PROGRAMA']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['COPIA_PROGRAMA']['USUARIO']      = 'insc_vestibular';
$SISCONF['DB']['COPIA_PROGRAMA']['SENHA']        = '@@9upkp0';
$SISCONF['DB']['COPIA_PROGRAMA']['HOST']         = "192.168.24.4";
$SISCONF['DB']['COPIA_PROGRAMA']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['COPIA_PROGRAMA']['BASE']         = "siga";
$SISCONF['DB']['COPIA_PROGRAMA']['LOGA_BD']      = false;

//Configuração Conexao Internet

$SISCONF['DB']['INTERNET']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['INTERNET']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['INTERNET']['USUARIO']      = 'mid';
$SISCONF['DB']['INTERNET']['SENHA']        = 'racalama06';
$SISCONF['DB']['INTERNET']['HOST']         = "192.168.1.2";
$SISCONF['DB']['INTERNET']['SID']          = "internet";
$SISCONF['DB']['INTERNET']['BASE']         = "internet";
$SISCONF['DB']['INTERNET']['LOGA_BD']      = false;

//Configurações do DESENV (BD de teste)
$SISCONF['DB']['SISTEMA']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['SISTEMA']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['SISTEMA']['USUARIO']      = 'sistemas';
//if(in_array(getenv ("REMOTE_ADDR"),array('10.10.10.87'))){
$SISCONF['DB']['SISTEMA']['SENHA']        = '123456';
//}else {
//$SISCONF['DB']['SISTEMA']['SENHA'] = '3xz@?0ta';
//}
$SISCONF['DB']['SISTEMA']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['SISTEMA']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['SISTEMA']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['SISTEMA']['LOGA_BD']      = true;

//Configurações do DESENV (BD de teste)
$SISCONF['DB']['DESENV']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['DESENV']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['DESENV']['USUARIO']      = 'sistemas';
//$SISCONF['DB']['DESENV']['SENHA'] = '3xz@?0ta';
$SISCONF['DB']['DESENV']['SENHA']        = '123456';
$SISCONF['DB']['DESENV']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['DESENV']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['DESENV']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['DESENV']['LOGA_BD']      = true;

//Configurações do DESENV (BD de teste)
$SISCONF['DB']['INTEGRACAO_GV']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['INTEGRACAO_GV']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['INTEGRACAO_GV']['USUARIO']      = 'integracao_gv';
$SISCONF['DB']['INTEGRACAO_GV']['SENHA']        = 'xpario#33@integra';
//$SISCONF['DB']['INTEGRACAO_GV']['HOST'] = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['INTEGRACAO_GV']['HOST']         = '192.168.1.86';
$SISCONF['DB']['INTEGRACAO_GV']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['INTEGRACAO_GV']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['INTEGRACAO_GV']['LOGA_BD']      = true;

//Configurações do DESENV (BD de teste)
$SISCONF['DB']['MASTER']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['MASTER']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
#$SISCONF['DB']['MASTER']['USUARIO'] = 'rafaelpelliccioli';
#$SISCONF['DB']['MASTER']['SENHA'] = 'rap*1711';
$SISCONF['DB']['MASTER']['USUARIO']      = 'tkmaster';
$SISCONF['DB']['MASTER']['SENHA']        = 'mn68!x05';
$SISCONF['DB']['MASTER']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['MASTER']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['MASTER']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['MASTER']['LOGA_BD']      = true;

//Configurações do LOG (BD de teste)
$SISCONF['DB']['LOG']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['LOG']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
#$SISCONF['DB']['LOG']['USUARIO'] = 'log';
#$SISCONF['DB']['LOG']['SENHA'] = 'xpariolog';
$SISCONF['DB']['LOG']['USUARIO']      = 'sistemas';
//$SISCONF['DB']['LOG']['SENHA'] = '3xz@?0ta';
$SISCONF['DB']['LOG']['SENHA']        = '123456';
$SISCONF['DB']['LOG']['HOST']         = $CONEXAO_PADRAO['HOST']; //'novatramandai.uniritter.edu.br';
$SISCONF['DB']['LOG']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['LOG']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['LOG']['LOGA_BD']      = false;

//Configurações do DESENV (BD de teste)
$SISCONF['DB']['EVENTOS']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['EVENTOS']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['EVENTOS']['USUARIO']      = 'sistemas';
$SISCONF['DB']['EVENTOS']['SENHA']        = 'xpariopostgres';
$SISCONF['DB']['EVENTOS']['HOST']         = 'localhost'; //'novatramandai.uniritter.edu.br';
$SISCONF['DB']['EVENTOS']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['EVENTOS']['BASE']         = 'siga2';
$SISCONF['DB']['EVENTOS']['LOGA_BD']      = false;

//Configurações do BD de PRODUÇÃO
$SISCONF['DB']['SIGA']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['SIGA']['USER_CONNECT'] = 'REQUEST';
$SISCONF['DB']['SIGA']['USUARIO']      = '';
$SISCONF['DB']['SIGA']['SENHA']        = '';
$SISCONF['DB']['SIGA']['HOST']         = 'localhost';
$SISCONF['DB']['SIGA']['SID']          = 'siga';
$SISCONF['DB']['SIGA']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['SIGA']['LOGA_BD']      = false;

//Configurações do BD de vestibular
$SISCONF['DB']['VESTIBULAR']['BANCO'] = 'POSTGRES';
$SISCONF['DB']['VESTIBULAR']['USER_CONNECT'] = 'DEFAULT';//'REQUEST';
#$SISCONF['DB']['VESTIBULAR']['USUARIO'] = 'insc_vestibular';//'insc_vestibular';
#$SISCONF['DB']['VESTIBULAR']['SENHA'] = '@@9upkp0';//'!v8s1@x';
$SISCONF['DB']['VESTIBULAR']['USUARIO'] = 'insc_vestibular';//'insc_vestibular';
$SISCONF['DB']['VESTIBULAR']['SENHA'] = '@@9upkp0';//'!v8s1@x';
//$SISCONF['DB']['VESTIBULAR']['SENHA'] = '123456';
//$SISCONF['DB']['VESTIBULAR']['SENHA'] = '@@9upkp0';//'@@9upkp0';
$SISCONF['DB']['VESTIBULAR']['HOST'] = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['VESTIBULAR']['SID'] = 'siga';
$SISCONF['DB']['VESTIBULAR']['BASE'] = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['VESTIBULAR']['LOGA_BD'] = false;

if (in_array(getenv("REMOTE_ADDR"), array(
    "10.11.10.15"
))) {
    $SISCONF['DB']['VESTIBULAR']['BANCO']        = 'POSTGRES';
    $SISCONF['DB']['VESTIBULAR']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
    $SISCONF['DB']['VESTIBULAR']['USUARIO']      = 'sistemas';
    $SISCONF['DB']['VESTIBULAR']['SENHA']        = '3xz@?0ta';
    $SISCONF['DB']['VESTIBULAR']['HOST']         = $CONEXAO_PADRAO['HOST'];
    $SISCONF['DB']['VESTIBULAR']['SID']          = 'siga';
    $SISCONF['DB']['VESTIBULAR']['BASE']         = $CONEXAO_PADRAO['BASE'];
    $SISCONF['DB']['VESTIBULAR']['LOGA_BD']      = false;
}

$SISCONF['DB']['SISTEMAS']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['SISTEMAS']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['SISTEMAS']['USUARIO']      = 'sistemas';
$SISCONF['DB']['SISTEMAS']['SENHA']        = '123456';
$SISCONF['DB']['SISTEMAS']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['SISTEMAS']['SID']          = 'siga';
$SISCONF['DB']['SISTEMAS']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['SISTEMAS']['LOGA_BD']      = false;

//Configurações do BD da FADERGS para Migração de contato comercial
$SISCONF['DB']['MIGRACAO_CONTATO']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['MIGRACAO_CONTATO']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['MIGRACAO_CONTATO']['USUARIO']      = $SISCONF['DB']['VESTIBULAR']['USUARIO'];
$SISCONF['DB']['MIGRACAO_CONTATO']['SENHA']        = $SISCONF['DB']['VESTIBULAR']['SENHA'];
$SISCONF['DB']['MIGRACAO_CONTATO']['HOST']         = "imbe";
$SISCONF['DB']['MIGRACAO_CONTATO']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['MIGRACAO_CONTATO']['BASE']         = "siga_fadergs_02092014";
$SISCONF['DB']['MIGRACAO_CONTATO']['LOGA_BD']      = false;


//Configurações do BD de publico
$SISCONF['DB']['PUBLICO']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['PUBLICO']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['PUBLICO']['USUARIO']      = 'insc_vestibular';
$SISCONF['DB']['PUBLICO']['SENHA']        = '@@9upkp0';
$SISCONF['DB']['PUBLICO']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['PUBLICO']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['PUBLICO']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['PUBLICO']['LOGA_BD']      = false;

//Configurações do BD de publico
$SISCONF['DB']['BLACKBOARD']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['BLACKBOARD']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['BLACKBOARD']['USUARIO']      = 'blackboard';
$SISCONF['DB']['BLACKBOARD']['SENHA']        = 'Bbd*2015';
$SISCONF['DB']['BLACKBOARD']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['BLACKBOARD']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['BLACKBOARD']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['BLACKBOARD']['LOGA_BD']      = false;


//Configurações do BD de integração PS
$SISCONF['DB']['INTEGRACAO_PS']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['INTEGRACAO_PS']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
#$SISCONF['DB']['INTEGRACAO_PS']['USUARIO'] = 'integracao_ps';
#$SISCONF['DB']['INTEGRACAO_PS']['SENHA'] = '';
$SISCONF['DB']['INTEGRACAO_PS']['USUARIO']      = 'sistemas';
$SISCONF['DB']['INTEGRACAO_PS']['SENHA']        = '123456';
if (in_array(getenv("REMOTE_ADDR"), array(
    "10.176.176.2"
))) {
    $SISCONF['DB']['INTEGRACAO_PS']['SENHA'] = '3xz@?0ta';
}
$SISCONF['DB']['INTEGRACAO_PS']['HOST']    = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['INTEGRACAO_PS']['SID']     = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['INTEGRACAO_PS']['BASE']    = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['INTEGRACAO_PS']['LOGA_BD'] = false;

//Configurações do BD de publico
$SISCONF['DB']['CRONLOG_NOTAS_FALTAS']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['CRONLOG_NOTAS_FALTAS']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['CRONLOG_NOTAS_FALTAS']['USUARIO']      = 'cronlog_notas_faltas';
$SISCONF['DB']['CRONLOG_NOTAS_FALTAS']['SENHA']        = 'Cr013N&49F';
$SISCONF['DB']['CRONLOG_NOTAS_FALTAS']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['CRONLOG_NOTAS_FALTAS']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['CRONLOG_NOTAS_FALTAS']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['CRONLOG_NOTAS_FALTAS']['LOGA_BD']      = false;

//Configurações do BD de webservice
$SISCONF['DB']['WEBSERVICE']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['WEBSERVICE']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['WEBSERVICE']['USUARIO']      = 'siga_webservice';
$SISCONF['DB']['WEBSERVICE']['SENHA']        = '123';
$SISCONF['DB']['WEBSERVICE']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['WEBSERVICE']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['WEBSERVICE']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['WEBSERVICE']['LOGA_BD']      = false;

//Configurações do BD de publico
$SISCONF['DB']['BI']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['BI']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['BI']['USUARIO']      = 'bi';
$SISCONF['DB']['BI']['SENHA']        = '@@9upkp0';
$SISCONF['DB']['BI']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['BI']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['BI']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['BI']['LOGA_BD']      = false;

//Configurações do BD de PRODUÇÃO
$SISCONF['DB']['ALUNOS']['BANCO']        = 'MYSQL';
$SISCONF['DB']['ALUNOS']['USER_CONNECT'] = 'DEFAULT';
$SISCONF['DB']['ALUNOS']['USUARIO']      = 'sistemas';
$SISCONF['DB']['ALUNOS']['SENHA']        = 'xpariobd';
$SISCONF['DB']['ALUNOS']['HOST']         = 'ischool.uniritter.edu.br'; //$SISCONF['DB']['ALUNOS']['HOST'] = 'localhost';
$SISCONF['DB']['ALUNOS']['SID']          = 'ALUNOS';
$SISCONF['DB']['ALUNOS']['BASE']         = 'ischoolathens';
$SISCONF['DB']['ALUNOS']['LOGA_BD']      = false;

//Configurações do PARSER de BD para Matrizes
$SISCONF['DB']['MATRIX']['BANCO']        = 'MATRIX';
$SISCONF['DB']['MATRIX']['USER_CONNECT'] = 'DEFAULT';
$SISCONF['DB']['MATRIX']['USUARIO']      = 'x';
$SISCONF['DB']['MATRIX']['SENHA']        = 'x';
$SISCONF['DB']['MATRIX']['HOST']         = 'x';
$SISCONF['DB']['MATRIX']['BASE']         = 'x';
$SISCONF['DB']['MATRIX']['SID']          = 'x';
$SISCONF['DB']['MATRIX']['LOGA_BD']      = false;

//Configurações do AD
$SISCONF['AD']['SIGA']['SUFIXO']        = "@fake.local";
$SISCONF['AD']['SIGA']['BASE']          = "DC=fake,DC=local";
$SISCONF['AD']['SIGA']['HOSTS'][0]      = "10.0.50.000";
$SISCONF['AD']['SIGA']['HOSTS'][1]      = "10.0.50.001";

if ($SISCONF['SIS']['AMBIENTE'] == "UNIFACS_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "UNP_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "UAM_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "UNIRITTER_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "IBMR_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "UNIFG_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "FPB_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "BSP_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "CEDEPE_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "FIAMFAAM_EAD") {
} elseif ($SISCONF['SIS']['AMBIENTE'] == "FMU_EAD" || $SISCONF['SIS']['AMBIENTE'] == "EAD") {
    /*
        $SISCONF['AD']['SIGA']['SUFIXO']        = "@eadlaureate.local";
        $SISCONF['AD']['SIGA']['BASE']          = "DC=eadlaureate,DC=local";
        $SISCONF['AD']['SIGA']['HOSTS'][0]      = "10.0.50.207";
        $SISCONF['AD']['SIGA']['HOSTS'][1]      = "10.0.50.204";
    */
} elseif ($SISCONF['SIS']['AMBIENTE'] == "FADERGS_EAD") {
    /*
        $SISCONF['AD']['SIGA']['SUFIXO']        = "@eadfadergs.local";
        $SISCONF['AD']['SIGA']['BASE']          = "DC=eadfadergs,DC=local";
        $SISCONF['AD']['SIGA']['HOSTS'][0]      = "192.168.50.213";
    */
}

$SISCONF['AD']['SIGA']['USUARIO']       = "admSigaPHP";
$SISCONF['AD']['SIGA']['SENHA']         = "332!@17f";
$SISCONF['AD']['SIGA']['SSL']           = true;
$SISCONF['AD']['SIGA']['PREFIXO_LOGIN'] = "alu";

//Configurações do PERGAMUM
if ($SISCONF['SIS']['AMBIENTE'] == "UNIRITTER") {
    $SISCONF['DB']['PERGAMUM']['USUARIO'] = 'sync_sigaperga';
    $SISCONF['DB']['PERGAMUM']['SENHA']   = 'P$syNC1217@';
    $SISCONF['DB']['PERGAMUM']['SERVICO'] = "pergamarc_hmg";
    $SISCONF['DB']['PERGAMUM']['BASE']    = "pergamarc_hmg";
} elseif ($SISCONF['SIS']['AMBIENTE'] == "ESADE") {
    $SISCONF['DB']['PERGAMUM']['USUARIO'] = 'sync_sigaperga';
    $SISCONF['DB']['PERGAMUM']['SENHA']   = 'P$syNC1217@';
    $SISCONF['DB']['PERGAMUM']['SERVICO'] = "pergamarc_fadergs"; //"pergamum";
    $SISCONF['DB']['PERGAMUM']['BASE']    = "pergamarc_fadergs";
}


if ($SISCONF['SIS']['AMBIENTE'] == "UNIRITTER") {
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['BANCO']   = 'MSSQL';
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['USUARIO'] = 'bibinternet';
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['SENHA']   = 'mxabf1';
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['SERVICO'] = "pergamarc_hmg";
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['BASE']    = "pergamarc_hmg";
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['HOST']    = "pergamarc_hmg";
} else {
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['USUARIO'] = 'bibinternet';
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['SENHA']   = 'mxabf1';
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['SERVICO'] = "pergamarc_fadergs";
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['BASE']    = "pergamarc_fadergs";
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['BANCO']   = "MSSQL";
    //$SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['BANCO'] = "pergamarc_fadergs";
    $SISCONF['DB']['PERGAMUM_PLANO_ENSINO']['HOST']    = "pergamarc_fadergs";
}

//Configurações do CRM
$SISCONF['DB']['CRM']['BANCO']        = 'MYSQL';
$SISCONF['DB']['CRM']['HOST']         = 'imbe.uniritter.local';
$SISCONF['DB']['CRM']['USER_CONNECT'] = 'DEFAULT';
$SISCONF['DB']['CRM']['USUARIO']      = 'crm_user';
$SISCONF['DB']['CRM']['SENHA']        = 'CrMU$3r*';
$SISCONF['DB']['CRM']['BASE']         = "crm";

//CONFIGURAÇÕES DO GVCOLLEGE
$SISCONF['DB']['GVCOLLEGE']['BANCO']        = 'MSSQL';
$SISCONF['DB']['GVCOLLEGE']['HOST']         = 'gvcollege.esade.edu.br:1433';
$SISCONF['DB']['GVCOLLEGE']['USER_CONNECT'] = 'DEFAULT';
$SISCONF['DB']['GVCOLLEGE']['USUARIO']      = 'sync_avaliacao';
$SISCONF['DB']['GVCOLLEGE']['SENHA']        = 'SynC*2011o';
$SISCONF['DB']['GVCOLLEGE']['BASE']         = "gvcollege_ESADE";

//CONFIGURAÇÕES DO TOTVS
$SISCONF['DB']['TOTVS']['BANCO']        = 'MSSQL';
$SISCONF['DB']['TOTVS']['HOST']         = '10.161.1.37:1433';
$SISCONF['DB']['TOTVS']['USER_CONNECT'] = 'DEFAULT';
$SISCONF['DB']['TOTVS']['USUARIO']      = 'sync_avaliacao';
$SISCONF['DB']['TOTVS']['SENHA']        = 'SynC*2011o';
$SISCONF['DB']['TOTVS']['BASE']         = "gvcollege_ESADE";

//Configurações do BD de publico
$SISCONF['DB']['LOGIN_PESSOA_EXTERNA']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['LOGIN_PESSOA_EXTERNA']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['LOGIN_PESSOA_EXTERNA']['USUARIO']      = 'login_pessoa_externa';
$SISCONF['DB']['LOGIN_PESSOA_EXTERNA']['SENHA']        = '1n$cr!c@0';
$SISCONF['DB']['LOGIN_PESSOA_EXTERNA']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['LOGIN_PESSOA_EXTERNA']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['LOGIN_PESSOA_EXTERNA']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['LOGIN_PESSOA_EXTERNA']['LOGA_BD']      = false;

if ($_SERVER['REMOTE_ADDR'] == '10.176.176.16456') {
    /*$SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['BANCO'] = 'POSTGRES';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['USER_CONNECT'] = 'DEFAULT';//'REQUEST';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['USUARIO'] = 'rel_financeiro_cron';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['SENHA'] = 'rel@cr0n!';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['HOST'] = 'cobalt.fadergs.edu.br';//'novatramandai.uniritter.edu.br';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['SID'] = 'siga';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['BASE'] = 'siga';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['LOGA_BD'] = true;*/
} else {
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['BANCO']        = 'POSTGRES';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['USUARIO']      = 'rel_financeiro_cron';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['SENHA']        = 'rel@cr0n!';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['HOST']         = $CONEXAO_PADRAO['HOST']; //'novatramandai.uniritter.edu.br';
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['SID']          = $CONEXAO_PADRAO['SID'];
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['BASE']         = $CONEXAO_PADRAO['BASE'];
    $SISCONF['DB']['RELATORIOS_FINANCEIROS_CRON']['LOGA_BD']      = true;
}

/*if($_SERVER['REMOTE_ADDR'] == '10.11.10.8'){// && strpos($_SERVER['DOCUMENT_ROOT'], "juliano_cezaro/public_html/servicos/integracoes") > 0){
//echo "<h1>INFOSIGA PRODUÇÃO</h1>";
$SISCONF['DB']['INFOSIGA']['BANCO'] = 'MYSQL';
$SISCONF['DB']['INFOSIGA']['USER_CONNECT'] = 'DEFAULT';
$SISCONF['DB']['INFOSIGA']['USUARIO'] = 'siga';
$SISCONF['DB']['INFOSIGA']['SENHA'] = 's1gAMySQL*1655';
$SISCONF['DB']['INFOSIGA']['HOST'] = 'curumim.uniritter.edu.br';
$SISCONF['DB']['INFOSIGA']['SID'] = 'infosiga_uniritter';
$SISCONF['DB']['INFOSIGA']['BASE'] = 'infosiga_uniritter';
$SISCONF['DB']['INFOSIGA']['LOGA_BD'] = false;
}else {*/
$SISCONF['DB']['INFOSIGA']['BANCO']        = 'MYSQL';
$SISCONF['DB']['INFOSIGA']['USER_CONNECT'] = 'DEFAULT';
$SISCONF['DB']['INFOSIGA']['USUARIO']      = 'siga';
$SISCONF['DB']['INFOSIGA']['SENHA']        = 's1gAMySQL*1655';
$SISCONF['DB']['INFOSIGA']['HOST']         = 'curumim.uniritter.edu.br'; //10.176.255.55
$SISCONF['DB']['INFOSIGA']['SID']          = 'infosiga_uniritter_hmg';
$SISCONF['DB']['INFOSIGA']['BASE']         = 'infosiga_uniritter_hmg';
$SISCONF['DB']['INFOSIGA']['LOGA_BD']      = false;
//}

//Configuração do PATH padrão para os relatórios .PDF
$SISCONF['SIS']['RELATORIO_PDF']['PATH'] = $SISCONF['SIS']['HOST'] . $SISCONF['SIS']['PATH_SIGA'] . "/modulos/relatorios/";
#$SISCONF['SIS']['RELATORIO_PDF']['HOST'] = $SISCONF['SIS']['INTRANET']['HOST']."/siga/modulos/relatorios/";

//Configuração do PATH padrão dos arquivos chave do PORTAL SIGA
$SISCONF['PORTAL']['PATH'] = '/siga/';
#$SISCONF['PORTAL']['HOST'] = 'http://siga2.uniritter.edu.br/';
$SISCONF['PORTAL']['MAIN'] = 'siga.php';

//configuracoes de depuracao
$SISCONF['SIS']['DEBUG']    = false;
$SISCONF['SIS']['DEBUG_IP'] = array();
array_push($SISCONF['SIS']['DEBUG_IP'], '192.168.5.136');
array_push($SISCONF['SIS']['DEBUG_IP'], '192.168.5.???');

$SISCONF['SIS']['QUERIES'] = array();
$SISCONF['SIS']['EVENTS']  = array();

GLOBAL $ERRO_MSG;
$ERRO_MSG[1]  = "NÃO FOI POSS??VEL EFETUAR LOGIN NO BANCO DE DADOS";
$ERRO_MSG[2]  = "NÃO FOI POSS??VEL EFETUAR LOGIN NO SISTEMA - USU??RIO OU SENHA INV??LIDA";
$ERRO_MSG[3]  = "NÃO FOI POSS??VEL EFETUAR LOGIN NO SISTEMA - USU??RIO DESATIVADO";
$ERRO_MSG[4]  = "ERRO NA EXECUÇÃO DE COMANDO NO BANCO DE DADOS";
$ERRO_MSG[5]  = "FALHA DE COMUNICAÇÃO COM O BANCO DE DADOS";
$ERRO_MSG[6]  = "ERRO INTERNO DE APLICAÇÃO - VALORES INESPERADOS";
$ERRO_MSG[7]  = "A OPERAÇÃO DE REENVIO DE DADOS NÃO É ACEITA PARA ESTA P??GINA";
$ERRO_MSG[8]  = "FALHA NA EXECUÇÃO DE COMANDO EM LOTE. NÃO FOI POSS??VEL DESFAZER AS OPERAÇÕES REALIZADAS";
$ERRO_MSG[9]  = "FALHA NA EXECUÇÃO DE COMANDO EM LOTE. AS OPERAÇÕES REALIZADAS FORAM DESFEITAS";
$ERRO_MSG[10] = "NÃO FOI POSS??VEL CRIAR O ARQUIVO - J?? EXISTE UM ARQUIVO COM O MESMO NOME";
$ERRO_MSG[11] = "NÃO FOI POSS??VEL ESCREVER OS DADOS NO ARQUIVO";
$ERRO_MSG[12] = "NÃO FOI POSS??VEL FECHAR O ARQUIVO EM USO";
$ERRO_MSG[13] = "NÃO FOI POSS??VEL EXCLUIR O REGISTRO. EXISTEM DADOS VINCULADOS QUE IMPEDEM A OPERAÇÃO";
$ERRO_MSG[14] = "NÃO FOI POSS??VEL INSERIR O REGISTRO. J?? EXISTE UM REGISTRO CADASTRADO COM AS OPÇÕES SELECIONADAS";

GLOBAL $MSG_PADRAO;

$MSG_PADRAO['PADRAO']['TITULO'] = "Mensagem do Sistema";

$MSG_PADRAO['CAMPOS_NAO_PREENCHIDOS']['TITULO']    = "Campos não preenchidos!";
$MSG_PADRAO['CAMPOS_NAO_PREENCHIDOS']['DESCRICAO'] = "Os seguintes campos devem ser preenchidos: ";
$MSG_PADRAO['CAMPOS_INVALIDOS']['TITULO']          = "Campos com formato inválido!";
$MSG_PADRAO['CAMPOS_INVALIDOS']['DESCRICAO']       = "Os seguintes campos estão com seu formato inválido: ";
$MSG_PADRAO['CADASTRO_EFETUADO']['TITULO']         = $MSG_PADRAO['PADRAO']['TITULO'];
$MSG_PADRAO['CADASTRO_EFETUADO']['DESCRICAO']      = "Cadastro efetuado com sucesso!";
$MSG_PADRAO['ATUALIZACAO_EFETUADA']['TITULO']      = $MSG_PADRAO['PADRAO']['TITULO'];
$MSG_PADRAO['ATUALIZACAO_EFETUADA']['DESCRICAO']   = "Atualização efetuada com sucesso!";
$MSG_PADRAO['ALTERACAO_EFETUADA']['TITULO']        = $MSG_PADRAO['PADRAO']['TITULO'];
$MSG_PADRAO['ALTERACAO_EFETUADA']['DESCRICAO']     = "Alteração efetuada com sucesso!";
$MSG_PADRAO['EXCLUSAO_EFETUADA']['TITULO']         = $MSG_PADRAO['PADRAO']['TITULO'];
$MSG_PADRAO['EXCLUSAO_EFETUADA']['DESCRICAO']      = "Exclusão efetuada com sucesso!";
$MSG_PADRAO['EXCLUSAO_EFETUADA']['COMFIRMACAO']    = "Você tem certeza que deseja efetuar a exclusão dos registro((s)? Esta operação é irreversível.";
$MSG_PADRAO['CADASTRO_ERRO']['TITULO']             = $MSG_PADRAO['PADRAO']['TITULO'];
$MSG_PADRAO['CADASTRO_ERRO']['DESCRICAO']          = "Houve um erro ao efetuar a operação!";
$MSG_PADRAO['OPERACAO_INVALIDA']['TITULO']         = "Operação Inválida";
$MSG_PADRAO['OPERACAO_INVALIDA']['DESCRICAO']      = "Houve um erro ao processar a sua solicitação!";
$MSG_PADRAO['PERIODO_INVALIDO']['TITULO']          = "Período Inválido";
$MSG_PADRAO['PERIODO_INVALIDO']['DESCRICAO']       = "O período inicial não pode ser maior que o final!";
$MSG_PADRAO['INTERVALO_INVALIDO']['TITULO']        = "Intervalo Inválido";
$MSG_PADRAO['INTERVALO_INVALIDO']['DESCRICAO']     = "O valor mínimo não pode ser maior que o máximo!";
$MSG_PADRAO['EMAIL_ENVIADO']['TITULO']             = $MSG_PADRAO['PADRAO']['TITULO'];
$MSG_PADRAO['EMAIL_ENVIADO']['DESCRICAO']          = "O e-mail de confirmação foi enviado<br> com sucesso!";
$MSG_PADRAO['EMAIL_ERRO']['TITULO']                = $MSG_PADRAO['PADRAO']['TITULO'];
$MSG_PADRAO['EMAIL_ERRO']['DESCRICAO']             = "Ocorreu um erro ao enviar o e-mail<br> de confirmação!";

$MSG_PADRAO['OBS']['MODO_EDICAO'] = "* Modo de Edição";

$MSG_PADRAO['AVISO']['NAO_TESTE']    = "AVISO: Os dados contidos nesse programa utilizam-se de dados oficiais. <br />Portanto, NÃO utilize-o para TESTES.";
$MSG_PADRAO['AVISO']['SEM_REGISTRO'] = "Nenhum registro foi encontrado!";

$MSG_PADRAO['CADASTRO']['EFETUADO']['TITULO']     = $MSG_PADRAO['CADASTRO_EFETUADO']['TITULO'];
$MSG_PADRAO['CADASTRO']['EFETUADO']['DESCRICAO']  = $MSG_PADRAO['CADASTRO_EFETUADO']['DESCRICAO'];
$MSG_PADRAO['CADASTRO']['ERRO']['TITULO']         = $MSG_PADRAO['CADASTRO_ERRO']['TITULO'];
$MSG_PADRAO['CADASTRO']['ERRO']['DESCRICAO']      = $MSG_PADRAO['CADASTRO_ERRO']['DESCRICAO'];
$MSG_PADRAO['ALTERACAO']['EFETUADO']['TITULO']    = $MSG_PADRAO['ALTERACAO_EFETUADA']['TITULO'];
$MSG_PADRAO['ALTERACAO']['EFETUADO']['DESCRICAO'] = $MSG_PADRAO['ALTERACAO_EFETUADA']['DESCRICAO'];
$MSG_PADRAO['ALTERACAO']['ERRO']['TITULO']        = $MSG_PADRAO['CADASTRO_ERRO']['TITULO'];
$MSG_PADRAO['ALTERACAO']['ERRO']['DESCRICAO']     = $MSG_PADRAO['CADASTRO_ERRO']['DESCRICAO'];
$MSG_PADRAO['EXCLUSAO']['EFETUADO']['TITULO']     = $MSG_PADRAO['EXCLUSAO_EFETUADA']['TITULO'];
$MSG_PADRAO['EXCLUSAO']['EFETUADO']['DESCRICAO']  = $MSG_PADRAO['EXCLUSAO_EFETUADA']['DESCRICAO'];
$MSG_PADRAO['EXCLUSAO']['ERRO']['TITULO']         = $MSG_PADRAO['CADASTRO_ERRO']['TITULO'];
$MSG_PADRAO['EXCLUSAO']['ERRO']['DESCRICAO']      = $MSG_PADRAO['CADASTRO_ERRO']['DESCRICAO'];

$MSG_PADRAO['CONSULTA']['EFETUADO']['TITULO']    = $MSG_PADRAO['PADRAO']['TITULO'];
$MSG_PADRAO['CONSULTA']['EFETUADO']['DESCRICAO'] = "Consulta Efetuada com Sucesso!";
$MSG_PADRAO['CONSULTA']['ERRO']['TITULO']        = $MSG_PADRAO['PADRAO']['TITULO'];
$MSG_PADRAO['CONSULTA']['ERRO']['DESCRICAO']     = "Houve falha ao efetuar a consulta!";

$MSG_PADRAO['TELA_LOGIN'] = "* Utilize o mesmo usuário/senha do EAD, Agendamento e<br/> dos computadores do UniRitter.";

GLOBAL $TIPO_PROGRAMA;

$TIPO_PROGRAMA['1'] = "PROGRAMA";
$TIPO_PROGRAMA['2'] = "RELATÓRIO";
$TIPO_PROGRAMA['3'] = "EXTERNO";

GLOBAL $TIPO_PROGRAMA_REV;

$TIPO_PROGRAMA_REV['PROGRAMA']   = "1";
$TIPO_PROGRAMA_REV['RELATÓRIO'] = "2";
$TIPO_PROGRAMA_REV['EXTERNO']    = "3";

GLOBAL $TIPO_CAMPOS_AVALIACAO;

$TIPO_CAMPOS_AVALIACAO['SEL']['DESCRICAO'] = "Seleção (Combo Box)";
$TIPO_CAMPOS_AVALIACAO['SEL']['LARGURA']   = "50";
$TIPO_CAMPOS_AVALIACAO['SEL']['MAX_LEN']   = "0";
$TIPO_CAMPOS_AVALIACAO['TXT']['DESCRICAO'] = "Texto";
$TIPO_CAMPOS_AVALIACAO['TXT']['LARGURA']   = "50";
$TIPO_CAMPOS_AVALIACAO['TXT']['MAX_LEN']   = "128";
$TIPO_CAMPOS_AVALIACAO['TXA']['DESCRICAO'] = "??rea de Texto";
$TIPO_CAMPOS_AVALIACAO['TXA']['LARGURA']   = "50";
$TIPO_CAMPOS_AVALIACAO['TXA']['ALTURA']    = "4";
$TIPO_CAMPOS_AVALIACAO['TXA']['MAX_LEN']   = "2048";
$TIPO_CAMPOS_AVALIACAO['RAD']['DESCRICAO'] = "Escolha Única (Radio Button)";
$TIPO_CAMPOS_AVALIACAO['RAD']['LARGURA']   = "0";
$TIPO_CAMPOS_AVALIACAO['RAD']['MAX_LEN']   = "0";
$TIPO_CAMPOS_AVALIACAO['CHK']['DESCRICAO'] = "Múltipla Escolha (Check Box)";
$TIPO_CAMPOS_AVALIACAO['CHK']['LARGURA']   = "0";
$TIPO_CAMPOS_AVALIACAO['CHK']['MAX_LEN']   = "0";

GLOBAL $ARR_CAMPOS_AVALIACAO;

$ARR_CAMPOS_AVALIACAO['SEL'] = $TIPO_CAMPOS_AVALIACAO['SEL']['DESCRICAO'];
$ARR_CAMPOS_AVALIACAO['TXT'] = $TIPO_CAMPOS_AVALIACAO['TXT']['DESCRICAO'];
$ARR_CAMPOS_AVALIACAO['TXA'] = $TIPO_CAMPOS_AVALIACAO['TXA']['DESCRICAO'];
$ARR_CAMPOS_AVALIACAO['RAD'] = $TIPO_CAMPOS_AVALIACAO['RAD']['DESCRICAO'];
$ARR_CAMPOS_AVALIACAO['CHK'] = $TIPO_CAMPOS_AVALIACAO['CHK']['DESCRICAO'];


GLOBAL $STATUS_REG;
$STATUS_REG['ATIVADO']    = 1;
$STATUS_REG['DESATIVADO'] = 2;

GLOBAL $LOG;
$LOG['NIVEL']              = "1111";
/*Logout - Login - Autorizacao - Execução de Regra*/
$LOG['POS']['LOGOUT']      = 0;
$LOG['POS']['LOGIN']       = 1;
$LOG['POS']['AUTORIZACAO'] = 2;
$LOG['POS']['EXECUCAO']    = 3;

$LOG['TIPO']['LOGOUT']      = 1;
$LOG['TIPO']['LOGIN']       = 2;
$LOG['TIPO']['AUTORIZACAO'] = 3;
$LOG['TIPO']['EXECUCAO']    = 4;
$LOG['TIPO']['1']           = "LOGOUT";
$LOG['TIPO']['2']           = "LOGIN";
$LOG['TIPO']['3']           = "AUTORIZACAO";
$LOG['TIPO']['4']           = "EXECUCAO";

GLOBAL $MODULO_INF;

$MODULO_INF['ADMINISTRATIVO']['ID']                 = 1;
$MODULO_INF['ADMINISTRATIVO']['HABILITADO']         = true;
$MODULO_INF['COMERCIAL']['ID']                      = 97;
$MODULO_INF['COMERCIAL']['HABILITADO']              = true;
$MODULO_INF['CAIXA']['ID']                          = 41;
$MODULO_INF['CAIXA']['HABILITADO']                  = true;
$MODULO_INF['FINANCEIRO']['ID']                     = 33;
$MODULO_INF['FINANCEIRO']['HABILITADO']             = true;
$MODULO_INF['GESTAO_RECURSOS']['ID']                = 4;
$MODULO_INF['GESTAO_RECURSOS']['HABILITADO']        = true;
$MODULO_INF['INFORMACOES_GERENCIAIS']['ID']         = 0;
$MODULO_INF['INFORMACOES_GERENCIAIS']['HABILITADO'] = false;
$MODULO_INF['PROCESSO_SELECAO']['ID']               = 2;
$MODULO_INF['PROCESSO_SELECAO']['HABILITADO']       = true;
$MODULO_INF['CONTROLE_ACADEMICO']['ID']             = 3;
$MODULO_INF['CONTROLE_ACADEMICO']['HABILITADO']     = true;
$MODULO_INF['SISTEMAS']['ID']                       = 5;
$MODULO_INF['SISTEMAS']['HABILITADO']               = true;
$MODULO_INF['PESSOAS']['ID']                        = 14;
$MODULO_INF['PESSOAS']['HABILITADO']                = true;
$MODULO_INF['EVENTOS']['ID']                        = 69;
$MODULO_INF['EVENTOS']['HABILITADO']                = true;
$MODULO_INF['PESQUISA_EXTENSAO']['ID']              = 80;
$MODULO_INF['PESQUISA_EXTENSAO']['HABILITADO']      = true;

// PORTAL PROFESSORES
$MODULO_INF['PROFESSORES']['ACADEMICO']['ID']              = 28;
$MODULO_INF['PROFESSORES']['ACADEMICO']['HABILITADO']      = true;
$MODULO_INF['PROFESSORES']['AJUDA']['ID']                  = 32;
$MODULO_INF['PROFESSORES']['AJUDA']['HABILITADO']          = true;
$MODULO_INF['PROFESSORES']['DADOS_PESSOAIS']['ID']         = 29;
$MODULO_INF['PROFESSORES']['DADOS_PESSOAIS']['HABILITADO'] = true;
$MODULO_INF['PROFESSORES']['FORMULARIOS']['ID']            = 30;
$MODULO_INF['PROFESSORES']['FORMULARIOS']['HABILITADO']    = true;
$MODULO_INF['PROFESSORES']['LINKS']['ID']                  = 31;
$MODULO_INF['PROFESSORES']['LINKS']['HABILITADO']          = true;


//PORTAL ALUNOS
$MODULO_INF['ALUNOS']['ACADEMICO']['ID']              = 36;
$MODULO_INF['ALUNOS']['ACADEMICO']['HABILITADO']      = true;
$MODULO_INF['ALUNOS']['AJUDA']['ID']                  = 40;
$MODULO_INF['ALUNOS']['AJUDA']['HABILITADO']          = false;
$MODULO_INF['ALUNOS']['DADOS_PESSOAIS']['ID']         = 37;
$MODULO_INF['ALUNOS']['DADOS_PESSOAIS']['HABILITADO'] = false;
$MODULO_INF['ALUNOS']['FORMULARIOS']['ID']            = 38;
$MODULO_INF['ALUNOS']['FORMULARIOS']['HABILITADO']    = false;
$MODULO_INF['ALUNOS']['LINKS']['ID']                  = 39;
$MODULO_INF['ALUNOS']['LINKS']['HABILITADO']          = false;

//PORTAL SERVICOS
$MODULO_INF['SERVICOS']['FINANCEIRO']['ID']         = 87;
$MODULO_INF['SERVICOS']['FINANCEIRO']['HABILITADO'] = true;

//TIMEOUTS - TEMPOS EM MINUTOS
GLOBAL $TIMEOUT;
$TIMEOUT['PROFESSORES']['TEMPO_SESSAO']            = 180;
$TIMEOUT['PROFESSORES']['TEMPO_RESTANTE']          = 5;
$TIMEOUT['PROFESSORES']['MENSAGEM_TEMPO_RESTANTE'] = "Sua sessão irá expirar em " . $TIMEOUT['PROFESSORES']['TEMPO_RESTANTE'] . " minutos!\\\\nCertifique-se de que todos seus dados estão salvos!";

$TIMEOUT['ALUNOS']['TEMPO_SESSAO']            = 180;
$TIMEOUT['ALUNOS']['TEMPO_RESTANTE']          = 5;
$TIMEOUT['ALUNOS']['MENSAGEM_TEMPO_RESTANTE'] = "Sua sessão irá expirar em " . $TIMEOUT['ALUNOS']['TEMPO_RESTANTE'] . " minutos!\\\\nCertifique-se de que todos seus dados estão salvos!";

GLOBAL $CADASTRO_PADROES;

$CADASTRO_PADROES['PAIS']['ID']   = 1;
$CADASTRO_PADROES['ESTADO']['ID'] = 1;
$CADASTRO_PADROES['CIDADE']['ID'] = 1;

$CADASTRO_PADROES['PAGINA_INICIAL']['ID'] = 108;

$CADASTRO_PADROES['SISTEMA']['ID'] = 1;


GLOBAL $MAX_REG_PAGINA;
$MAX_REG_PAGINA = 50;

function dump($_objeto, $_usuario = null)
{
    GLOBAL $listaDesenvolvedores;
    if (in_array(sessao::getLogin(), $listaDesenvolvedores) || $_usuario == sessao::getLogin()) {
        echo "<pre>";
        echo var_export($_objeto, true);
        echo "</pre>";
    }
}


/**
 * Função para exibir o conteúdo de uma variável
 * @autor Diego Mancilha <diego_mancilha@uniritter.edu.br>
 */
function exibe($variavel, $descricao = '', $_usuario = null)
{
    GLOBAL $listaDesenvolvedores;
    if (in_array(sessao::getLogin(), $listaDesenvolvedores) || $_usuario == sessao::getLogin()) {
        $cor = '#FF0000';
        if (trim($descricao) != "") {
            echo "<font color='" . $cor . "'>Exibindo " . $descricao . "</font>";
        }
        echo "<pre>";
        print_r($variavel);
        echo "</pre>";
    }
}

/**
 * Função para manter compatibilidade dos fontes do php 4 para o 5
 * @autor Diego Mancilha <diego_mancilha@uniritter.edu.br>
 */
function clonaObjeto($obj)
{
    /*Para o php4 */
    //return $obj;

    /*Para o php5 */
    if (is_object($obj)) {
        $objClonado = clone $obj;
        return $objClonado;
    } else {
        return $obj;
    }
}

/**
 * Recebe dois valores e uma operação matemática a ser realizada e retorna o
 * resultado dessa operação. O cálculo é realizado utilizando as funções BCMath
 * @param float $_valor1 Primeiro valor envolvido no cálculo
 * @param float $_valor2 Segundo valor envolvido no cálculo
 * @param string $_operador Operador que identifica a operação de cálculo a ser realizada
 * @param integer $_precisao_retorno Precisão a ser utilizada no cálculo
 * @autor Diego Mancilha <diego_mancilha@uniritter.edu.br>
 * @return float
 */
function calcula($_valor1, $_valor2, $_operador = '+', $_precisao_retorno = 15)
{
    $resultado         = 0;
    $_precisao_interna = 999;
    switch ($_operador) {
        case '+':
            $resultado = bcadd($_valor1, $_valor2, $_precisao_interna);
            break;
        case '-':
            $resultado = bcsub($_valor1, $_valor2, $_precisao_interna);
            break;
        case '*':
            $resultado = bcmul($_valor1, $_valor2, $_precisao_interna);
            break;
        case '/':
            $resultado = bcdiv($_valor1, $_valor2, $_precisao_interna);
            break;
    }
    return (float) bcadd($resultado, 0, $_precisao_retorno);
}


//require_once $SISCONF['SIS']['COMUM']['SESSAO']."debug_function.inc";
function memorizeQuery($query = '')
{
    GLOBAL $SISCONF;
    //Comentada a instrução abaixo para otimização do uso de memória do servidor de produção
    array_push($SISCONF['SIS']['QUERIES'], $query);
}

//bloqueio de acesso ao servidor de producao
$SISCONF['SIS']['LOCK_PROD_IP'] = array();
array_push($SISCONF['SIS']['LOCK_PROD_IP'], '192.168.5.136');
array_push($SISCONF['SIS']['LOCK_PROD_IP'], '192.168.5.???');

function isLocked()
{
    GLOBAL $SISCONF;
    $ret = false;
    for ($d = 0; $d < count($SISCONF['SIS']['DEBUG_IP']); $d++) {
        if (isset($SISCONF['SIS']['LOCK_PROD_IP'][$d])) {
            if ($SISCONF['SESSAO']['USUARIO']['IP'] == $SISCONF['SIS']['LOCK_PROD_IP'][$d]) {
                $ret = true;
            }
        }
    }
    return $ret;
}

function isDeveloper()
{
    GLOBAL $SISCONF;
    $ret = false;
    for ($d = 0; $d < count($SISCONF['SIS']['DEBUG_IP']); $d++) {
        if ($SISCONF['SESSAO']['USUARIO']['IP'] == $SISCONF['SIS']['DEBUG_IP'][$d]) {
            $ret = true;
        }
    }
    return $ret;
}

require_once "comum/util/debug.class";

#COMENTARIO

$SISCONF['DEBUG']                   = new ext_debug_class();
$SISCONF['SESSAO']['USUARIO']['ID'] = 1;

$SISCONF['SERVIDOR_TESTE'] = true;
$SISCONF['PERIODO_AULA']   = 60;
define("SIGA_ALUNOS_ID", 759);

$SISCONF['SIS']['COMUM']['TKF_TEMPLATES'] = $SISCONF['SIS']['COMUM']['PATH'] . "tkfTemplates/";


//TKJasper Settings
//$SISCONF['SIS']['COMUM']['PEAR']  = $SISCONF['SIS']['COMUM']['PATH']."pear/";
//$SISCONF['SIS']['COMUM']['TKJASPER']  = $SISCONF['SIS']['COMUM']['PATH']."TKJasper/";

/*GLOBAL $JASPER;
$JASPER['SERVER']['ENDERECO'] = "ilheus.uniritter.edu.br";
$JASPER['SERVER']['PORTA'] = "8180";
$JASPER['SERVER']['SCHEMA'] = "http";
$JASPER['SERVER']['CAMINHO_SERVICOS'] = "/jasperserver/services/repository";
$JASPER['SERVER']['NAMESPACE'] = "http://www.jaspersoft.com/client";

$JASPER['SERVER']['TURKEY']['USUARIO'] = "siga_users";
$JASPER['SERVER']['TURKEY']['SENHA'] = "M@ryH45a!1tt!3L@mb";
$JASPER['SERVER']['PROFESSORES']['USUARIO'] = "siga_professores";
$JASPER['SERVER']['PROFESSORES']['SENHA'] = "W1!!K0mm3n";
$JASPER['SERVER']['ALUNOS']['USUARIO'] = "siga_alunos";
$JASPER['SERVER']['ALUNOS']['SENHA'] = "0m@m1t4b4";
$JASPER['SERVER']['EVENTOS']['USUARIO'] = "siga_externo";
$JASPER['SERVER']['EVENTOS']['SENHA'] = "H@Kun4M@t4t4";*/

$TIPO_PROGRAMA['4']              = "RELATÓRIO JASPER";
$TIPO_PROGRAMA_REV['REL_JASPER'] = "4";

$SISCONF['SIS']['LIQUID']['USUARIO'] = 'Admin';
$SISCONF['SIS']['LIQUID']['SENHA']   = 'R3d3Img2010';

$SISCONF['JS_HEADERS']['HELPER'] = "<script type=\"text/javascript\" src=\"" . $SISCONF['PATH_SCRIPT']['TURKEY'] . "helper.js\"></script>\n";

require_once $SISCONF['SIS']['COMUM']['SESSAO'] . "package_security_utils.class";

$SISCONF['DB']['RDSTATION']['BANCO']        = 'POSTGRES';
$SISCONF['DB']['RDSTATION']['USER_CONNECT'] = 'DEFAULT'; //'REQUEST';
$SISCONF['DB']['RDSTATION']['USUARIO']      = 'rdstation';
$SISCONF['DB']['RDSTATION']['SENHA']        = 'pHeb?wr4';
$SISCONF['DB']['RDSTATION']['HOST']         = $CONEXAO_PADRAO['HOST'];
$SISCONF['DB']['RDSTATION']['SID']          = $CONEXAO_PADRAO['SID'];
$SISCONF['DB']['RDSTATION']['BASE']         = $CONEXAO_PADRAO['BASE'];
$SISCONF['DB']['RDSTATION']['LOGA_BD']      = false;

$SISCONF['COBRANCA_BB']['WEBSERVICE']['URL_TOKEN']           = 'https://oauth.hm.bb.com.br/oauth/token';
$SISCONF['COBRANCA_BB']['WEBSERVICE']['URL_REGISTER']        = 'https://cobranca.homologa.bb.com.br:7101/registrarBoleto';
$SISCONF['COBRANCA_BB']['WEBSERVICE']['CA_CERTIFICATE_PATH'] = '/opt/www/bb.cert';
$SISCONF['COBRANCA_BB']['WEBSERVICE']['CLIENT_ID']           = 'eyJpZCI6IjgwNDNiNTMtZjQ5Mi00YyIsImNvZGlnb1B1YmxpY2Fkb3IiOjEwOSwiY29kaWdvU29mdHdhcmUiOjEsInNlcXVlbmNpYWxJbnN0YWxhY2FvIjoxfQ';
$SISCONF['COBRANCA_BB']['WEBSERVICE']['SECRET']              = 'eyJpZCI6IjBjZDFlMGQtN2UyNC00MGQyLWI0YSIsImNvZGlnb1B1YmxpY2Fkb3IiOjEwOSwiY29kaWdvU29mdHdhcmUiOjEsInNlcXVlbmNpYWxJbnN0YWxhY2FvIjoxLCJzZXF1ZW5jaWFsQ3JlZGVuY2lhbCI6MX0';


$SISCONF['WS']['URL_MODE_CLEAN'] = true;
$SISCONF['WS']['SECRET'] = '1234567890';
$SISCONF['WS']['ENVIRONMENT'] = 'DEV';
$SISCONF['WS']['PRIVATE_KEY'] = '-----BEGIN PRIVATE KEY-----
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
m2Vi1xeyXXzOw+0uIqP1OJYlN/ftEJQ=
-----END PRIVATE KEY-----';
