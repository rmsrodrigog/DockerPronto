<?php
//error_reporting(0 & ~E_STRICT & ~E_DEPRECATED & ~E_NOTICE);
error_reporting(E_ALL & ~E_NOTICE);
ini_set('display_errors',1);
ini_set('xdebug.var_display_max_depth', '10');
ini_set('xdebug.var_display_max_children', '256');
ini_set('xdebug.var_display_max_data', '1024');



GLOBAL $_GITDIR;

$_GITDIR = '/opt/www/.git/';

//----------------------------------------------------------------------------------------------------------------------
$REQUEST_SCHEME=$_SERVER['REQUEST_SCHEME']; // http || https || ...
$REQUEST_HOST=$_SERVER['HTTP_HOST'];
//----------------------------------------------------------------------------------------------------------------------

$prefix_arr = explode(".", $REQUEST_HOST);
$portal = $prefix_arr[0];
session_name($portal);
$ies_banco = $prefix_arr[1];
$is_opcao_banco_arr = explode("-", $ies_banco);
$ies = $is_opcao_banco_arr[0];
$banco = $is_opcao_banco_arr[1];
$ies_nome_completo = [
	"fad"=>"fadergs",
	"ibm"=>"ibmr",
	"ufg"=>"unifg",
	"unf"=>"unifacs",
	"unr"=>"uniritter",
	"unp"=>"unp",
	"fmu"=>"fmu",
	"uam"=>"uam",
	"fpb"=>"fpb",
	"bsp"=>"bsp",
];
if($ies_nome_completo[$ies] && count($prefix_arr) >= 3){
	$CONEXAO_PADRAO['HOST'] = ($banco=='fun')?'10.176.187.80':'10.176.187.14';
	$SISCONF['SIS']['AMBIENTE'] = strtoupper($ies_nome_completo[$ies]).'_EAD';
	$CONEXAO_PADRAO['BASE'] = 'siga_ead'.$ies.'_'.($banco=='fun'?'funcional':'dev');
}else{
	if(
		$_ENV['JETBRAINS_REMOTE_RUN']=="1"
		|| $_SERVER['argv'][0]=="vendor/bin/phpunit"
	) {
		$CONEXAO_PADRAO['HOST'] = '10.176.187.80';
		$SISCONF['SIS']['AMBIENTE'] = 'UAM_EAD'; //UNIRITTER, ESADE, FAPA, IBMR, EAD, UNIFACS_EAD
		$CONEXAO_PADRAO['BASE'] = 'siga_eaduam_funcional';		
	}else{
		echo "<br>AMBIENTE NÃO PARAMETRIZADO";
		echo "<br>REQUEST_HOST:".$REQUEST_HOST;
		echo "<br>HTTP_HOST:".$_SERVER['HTTP_HOST'];
		echo "<br>PHP_SELF:".$_SERVER['PHP_SELF'];
		die();
	}
}

$CONEXAO_PADRAO['PORT']=5432;
$CONEXAO_PADRAO['SID'] = $CONEXAO_PADRAO['BASE'];

$diretorioBase = '/opt/www';

$SISCONF['SIS']['COMERCIAL']['AMBIENTE'] = $SISCONF['SIS']['AMBIENTE'];

$LOCAL_PATH = [
    'TURKEY'=>[],
    'PROFESSORES'=>[],
    'ALUNOS'=>[],
    'VESTIBULAR'=>[],
    'POLOS'=>[],
    'EVENTOS'=>[],
    'API'=>[],
];

foreach($LOCAL_PATH as $portal=>$array_path) {
    $LOCAL_PATH[$portal]['CLASSES'] = $diretorioBase."/phpclasses";
	$LOCAL_PATH[$portal]['WEB_ROOT'] = $diretorioBase."";
}
$LOCAL_PATH['TURKEY']['WEB_ROOT'] = $diretorioBase."/siga";
$LOCAL_PATH['PROFESSORES']['WEB_ROOT'] = $diretorioBase."/portal/professores";
$LOCAL_PATH['ALUNOS']['WEB_ROOT'] = $diretorioBase."/portal/academicos";
$LOCAL_PATH['VESTIBULAR']['WEB_ROOT'] = $diretorioBase."/portal/vestibular";
$LOCAL_PATH['POLOS']['WEB_ROOT'] = $diretorioBase."/portal/polos";
$LOCAL_PATH['EVENTOS']['WEB_ROOT'] = $diretorioBase."/portal/eventos";
$LOCAL_PATH['API']['WEB_ROOT'] = $diretorioBase."/portal/servicos/api";
//localizacao do framework
$SISCONF['SIS']['FRAME']['PATH'] = $diretorioBase."/phpclasses/";

//localizacao do site e elementos internos
$SISCONF['SIS']['COMUM']['HOST']  = "http://siga.$ies_banco.localhost";
$SISCONF['SIS']['COMUM']['TEMAS'] = $SISCONF['SIS']['COMUM']['HOST']."/temas/";
$SISCONF['SIS']['COMUM']['IMAGENS'] = $SISCONF['SIS']['COMUM']['HOST']."/imagens/";
$SISCONF['SIS']['COMUM']['IMAGENS_TEMA'] = $SISCONF['SIS']['COMUM']['HOST']."/temas/comum/images/";
//$SISCONF['SIS']['POLOS']['HOST'] = $SISCONF['SIS']['COMUM']['HOST']."/portal/polos/";
//$SISCONF['SIS']['API']['HOST'] = $SISCONF['SIS']['COMUM']['HOST']."/portal/servicos/api/";
$SISCONF['SIS']['API']['HOST'] = "http://api.$ies_banco.localhost/";
$SISCONF['SIS']['POLOS']['HOST'] = "http://polos.$ies_banco.localhost/";
$SISCONF['SIS']['VESTIBULAR']['HOST'] = "http://selecao.$ies_banco.localhost/";

$SISCONF['PATH_WEB']['POLOS']['ROOT'] = $SISCONF['SIS']['POLOS']['HOST'];
$SISCONF['AJAX']['POLOS']['PROG_PATH']='/portal/polos/ajax/';

$URL_USO = $_SERVER['REQUEST_SCHEME']."://".$_SERVER['HTTP_HOST'].$_SERVER["REQUEST_URI"];

GLOBAL $PORTAL_POLOS;

$PORTAL_POLOS = false;


if(is_numeric(strpos($URL_USO, preg_replace('/^http{1,1}[s]{0,1}:\/\//', '', $SISCONF['SIS']['POLOS']['HOST'])))){
	$PORTAL_POLOS = true;
	$SISCONF['SIS']['NOME'] = "SIGA - PORTAL DO POLO";
	$SISCONF['SIS']['TITULO'] = "PORTAL DO POLO";
}

//Configurações de caminho do sistem academico
$SISCONF['PATH_WEB']['TURKEY']['ROOT'] = "/";

$SISCONF['PATH_WEB']['TURKEY']['LAYOUT']['DEFAULT'] = $SISCONF['PATH_WEB']['TURKEY']['ROOT']."layout/default/";

$SISCONF['PATH_SCRIPT']['TURKEY'] = $SISCONF['PATH_WEB']['TURKEY']['ROOT']."jscripts/";
$SISCONF['PATH_SCRIPT']['DEFAULT'] = $SISCONF['PATH_WEB']['TURKEY']['ROOT']."/jscripts";
$SISCONF['AJAX']['TURKEY']['PROG_PATH'] = $SISCONF['PATH_WEB']['TURKEY']['ROOT']."ajax/";

$SISCONF['SIS']['TURKEY']['HOST'] = $SISCONF['SIS']['COMUM']['HOST'].$SISCONF['PATH_WEB']['TURKEY']['ROOT'];

GLOBAL $__LOCAL_CONTEUDO_AJUDA;
$__LOCAL_CONTEUDO_AJUDA = $LOCAL_PATH['TURKEY']['WEB_ROOT']."layout/default/img/ajuda/";
GLOBAL $__WEB_CONTEUDO_AJUDA;
$__WEB_CONTEUDO_AJUDA = $SISCONF['PATH_WEB']['TURKEY']['LAYOUT']['DEFAULT']."img/ajuda/";

GLOBAL $__LOCAL_JWPLAYER;
$__LOCAL_JWPLAYER = $LOCAL_PATH['TURKEY']['WEB_ROOT']."jscripts/jwplayer/";
GLOBAL $__WEB_JWPLAYER;
$__WEB_JWPLAYER = $SISCONF['PATH_WEB']['TURKEY']['ROOT']."jscripts/jwplayer/";

$SISCONF['JQUERY'] = $SISCONF['PATH_SCRIPT']['TURKEY']."jquery/";
$SISCONF['GMAPS'] = $SISCONF['PATH_SCRIPT']['TURKEY']."gmaps/";

$SISCONF['SIS']['BASE'] = $LOCAL_PATH['TURKEY']['WEB_ROOT'];
$SISCONF['SIS']['HOST'] = $LOCAL_PATH['TURKEY']['WEB_ROOT'];

$SISCONF['ARQUIVOS']['INTERNO']['PATH']['LOCAL'] = $diretorioBase . "/dados/arquivos_web/";
$SISCONF['ARQUIVOS']['EXTERNO']['PATH']['LOCAL'] = $diretorioBase . "/dados/arquivos_web/";
$SISCONF['ARQUIVOS']['EXTERNO']['PATH']['WEB'] = "/dados/arquivos_web/";
$SISCONF['ARQUIVOS']['REGISTRO_PONTO'] = $SISCONF['ARQUIVOS']['INTERNO']['PATH']['LOCAL']."gestao_recursos/registro_ponto/";

$SISCONF['SIS']['PROFESSORES']['HOST'] = "http://professores.$ies_banco.localhost/";
$SISCONF['PATH_WEB']['PROFESSORES']['ROOT'] = $SISCONF['SIS']['PROFESSORES']['HOST'];
$SISCONF['SIS']['PROFESSORES']['ARQUIVOS']['EXTERNO']['PATH']['WEB'] = $SISCONF['ARQUIVOS']['EXTERNO']['PATH']['WEB'];

$SISCONF['SIS']['ALUNOS']['HOST'] = "http://estudantes.$ies_banco.localhost/";
$SISCONF['PATH_WEB']['ALUNOS']['ROOT'] = $SISCONF['SIS']['ALUNOS']['HOST'];
$SISCONF['SIS']['ALUNOS']['ARQUIVOS']['EXTERNO']['PATH']['WEB'] = $SISCONF['PATH_WEB']['TURKEY']['ROOT']."/arquivos_web/";

$SISCONF['SIS']['SERVICOS']['HOST'] = "http://servicos.$ies_banco.localhost/";
$SISCONF['PATH_WEB']['SERVICOS']['ROOT'] = "/";

$SISCONF['PATH_WEB']['SERVICOS']['ROOT'] = $SISCONF['SIS']['SERVICOS']['HOST'];
$SISCONF['PATH_WEB']['SERVICOS']['LAYOUT']['DEFAULT'] = $SISCONF['SIS']['SERVICOS']['HOST']."/layout/default/";
$SISCONF['PATH_SCRIPT']['SERVICOS'] = $SISCONF['SIS']['SERVICOS']['HOST']."/jscripts/";

$SISCONF['SIS']['SERVICOS_INTEGRACOES']['HOST'] = $SISCONF['SIS']['SERVICOS']['HOST']."integracoes/";
$LOCAL_PATH['SERVICOS_INTEGRACOES']['WEB_ROOT'] = $diretorioBase."/public_html/portal/servicos/integracoes/";

$SISCONF['SIS']['SHARED']['HOST'] = "$REQUEST_SCHEME://$REQUEST_HOST/__shared/";
$LOCAL_PATH['SHARED']['WEB_ROOT'] = "/"."/__shared";

//Configuração de caminho para biblioteca TinyMCE
$SISCONF['TINYMCE'] = $SISCONF['PATH_SCRIPT']['TURKEY']."tinymce/jscripts/tiny_mce/tiny_mce.js";

//---------------------------------------------------------------------------------------------------------

$SISCONF['SIS']['COMUM']['PATH']  = $SISCONF['SIS']['FRAME']['PATH']."comum/";

$SISCONF['FORMULARIOS']['EVENTOS']['HOST'] = "http://inscricao.$ies_banco.localhost/";
$SISCONF['FORMULARIOS']['EVENTOS']['PATH_WEB']['ROOT'] = "/";

$SISCONF['SIS']['EVENTOS']['HOST'] = "http://inscricao.$ies_banco.localhost/";

$TIPO_PROGRAMA['4'] = "RELATÓRIO JASPER";
$TIPO_PROGRAMA_REV['REL_JASPER'] = "4";

$SISCONF['PATH_SCRIPT']['VESTIBULAR'] = $SISCONF['SIS']['VESTIBULAR']['HOST']."/jscripts/";

$SISCONF['SIS']['TESTE']['HOST'] = $SISCONF['SIS']['COMUM']['HOST']."/teste/";
$SISCONF['PATH_WEB']['TESTE']['ROOT'] = "/teste/";

$SISCONF['COMPOSER']['PATH'] = $diretorioBase."/vendor/";

$SISCONF['SIS']['CERTIFICADO_WEBSERVICE']   = diretorioBase."/siga/cert";
$SISCONF['SIS']['TIPO_AMBIENTE_WEBSERVICE'] = 'T';
$SISCONF['SIS']['SEMPRE_IMPRIME_BOLETO']    = false;


$listaDesenvolvedores[] = 'insc_vestibular';
$listaDesenvolvedores[] = 'migracao';
$listaDesenvolvedores[] = 'migracao';
$listaDesenvolvedores[] = 'jeison.chollet';

$SISCONF["emails_teste"] = [
	"jeison_chollet@laureate.com.br" => "Jeison Chollet"
];

$SISCONF['COBRANCA_BB']['WEBSERVICE']['CLIENT_ID']           = 'eyJpZCI6IjgwNDNiNTMtZjQ5Mi00YyIsImNvZGlnb1B1YmxpY2Fkb3IiOjEwOSwiY29kaWdvU29mdHdhcmUiOjEsInNlcXVlbmNpYWxJbnN0YWxhY2FvIjoxfQ';
$SISCONF['COBRANCA_BB']['WEBSERVICE']['SECRET']              = 'eyJpZCI6IjBjZDFlMGQtN2UyNC00MGQyLWI0YSIsImNvZGlnb1B1YmxpY2Fkb3IiOjEwOSwiY29kaWdvU29mdHdhcmUiOjEsInNlcXVlbmNpYWxJbnN0YWxhY2FvIjoxLCJzZXF1ZW5jaWFsQ3JlZGVuY2lhbCI6MX0';
$SISCONF['COBRANCA_BB']['WEBSERVICE']['AMB']                 = 'HMG'; //PROD
