<?php include '../data/common.inc.php'; 
$diyid=$_GET['diyid'];
?>
<?php
//数据库连接信息
$mysql_server_name = $cfg_dbhost;
$mysql_database = $cfg_dbname;
$mysql_username = $cfg_dbuser;
$mysql_password = $cfg_dbpwd;

   $conn = mysql_connect($mysql_server_name,$mysql_username,$mysql_password) or die("couldn't open SQL Server ");
   mysql_query("set names 'gb2312'",$conn); 
   $results=mysql_db_query($mysql_database,"select column_comment from information_schema.columns where table_schema ='dedeform'  and table_name = 'dede_diyform".$diyid."'",$conn);


   $str = '';
   $i = 0;
   while($rows = mysql_fetch_row($results))   
    {  
			if($i != 1){
   				$str .= $rows[0];   //  设置表格的标头 不需要转换  iconv('UTF-8','GB2312',$rows[0])
				$str .= ",";
			}
		 	$i++;
	}
	$str .="\n";



 	$result=mysql_db_query($mysql_database,"SELECT * from dede_diyform".$diyid,$conn);
    while($row = mysql_fetch_row($result))   
    {     
	   
	   for($s=0;$s<$i;$s++) 
	   {  
	   		if($s != 1){
				$res = $row[$s];//中文转码 不需要转码 
				$str .= $res.',';
			}
		}

        $str .= "\n"; //用引文逗号分开   
    }  
    $filename = date('YmdHi').'.csv'; //设置文件名   
    export_csv($filename,$str); //导出   

	function export_csv($filename,$data)   
	{   
		header("Content-type:text/csv");   
		header("Content-Disposition:attachment;filename=".$filename);   
		header('Cache-Control:must-revalidate,post-check=0,pre-check=0');
        header('Expires:0');
        header('Pragma:public'); 
		echo $data;   
	}    
?>