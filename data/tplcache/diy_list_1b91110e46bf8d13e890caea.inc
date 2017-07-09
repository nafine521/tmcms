<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8 echo $cfg_soft_lang; ?>">
<title><?php echo $diy->name;?></title>
<link href="css/base.css" rel="stylesheet" type="text/css" />
</head>
<body background='images/allbg.gif' leftmargin='8' topmargin='8'>
<div class="bodytitle">
	<div class="bodytitleleft"></div>
	<div class="bodytitletxt" style="padding-left:10px;"><?php echo $diy->name;?>内容列表</div>
</div>
<form action="diy_list.php" method="post">
<input type="hidden" name="diyid" value="<?php echo $diyid;?>" />

<table width="98%" border="0" cellpadding="1" cellspacing="1" align="center" class="tbtitle" style="background:#CFCFCF;">
<tr>
<td height="28" background='images/tbg.gif'>
<div style='float:left'>&nbsp;<a href='diy_main.php'><b>自定义表单管理</b></a> &gt; <b>内容列表</b></div>
<div style='float:right;padding-right:8px;'>
<a href="../plus/diy.php?action=list&diyid=<?php echo $diy->diyid; ?>" target="_blank"><img src='images/gtk-tmp.png' align='left' title='预览' alt='预览' /><u>前台预览</u></a>
</div>
</td>
</tr>
</table>
<table width="98%" border="0" cellpadding="1" cellspacing="1" align="center" class="tbtitle" style="background:#CFCFCF;">
<tr>

<?php
echo '<tr bgcolor="#F8FDE3"><td width="5">ID</td>';
foreach($fieldlist as $field=>$fielddata)
{
echo '<td bgcolor="#ffffff" >'.$fielddata[0].'</td>';
}
echo '<td bgcolor="#ffffff" >状态</td><td bgcolor="#ffffff" >操作</td></tr>';

$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
 
if(!empty($fields))
{
$allowhtml = array('htmltext');
$fields['sta'] = $fields['ifcheck'] == 1 ? '已审核' : '未审核';    
echo '<tr bgcolor="#F8FDE3"><td width="5%"><input type="checkbox" name="id[]" value="'.$fields['id'].'" class="np" /><a href="diy_list.php?action=edit&diyid='.$diy->diyid.'&id='.$fields['id'].'">'.$fields['id'].'</a></td>';
foreach($fieldlist as $field=>$fielddata)
{
if($fielddata[1]=='img')
{
$fields[$field] = "<a href='{$fields[$field]}' target='_blank'><img src='images/channeladd.gif' border='0' /> 图片附件</a>\r\n";
}
else if($fielddata[1]=='addon')
{
$fields[$field] = "<a href='{$fields[$field]}' target='_blank'><img src='images/channeladd.gif' border='0' /> 其它附件</a>";
}
else
{
if(!in_array($fielddata[1],$allowhtml)){
$fields[$field] = htmlspecialchars($fields[$field]);
}
}
echo '<td bgcolor="#ffffff">'.$fields[$field].'</td>';
}
echo '<td>'.$fields['sta'].'</td><td width="10%" align="center"><a href="diy_list.php?action=edit&diyid='.$diy->diyid.'&id='.$fields['id'].'"><img src="images/feedback-edit.gif" border="0" width="45" height="18"></a></td>';
echo '</tr>';
} else {
echo "<tr><td bgcolor=\"#ffffff\">暂无记录</td></tr>";
}

}
}?>
</table>
<table width="98%" border="0" cellpadding="1" cellspacing="1" align="center" style="background:#CFCFCF; margin-top:10px;">
<tr><td colspan="3" bgcolor="#ffffff"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</td></tr>
<tr>
<td colspan="3" height='36' align="center" bgcolor="#F8FCF1">
	<label><input type="radio" name="action" value="check" class='np' />审核</label>
	<label><input type="radio" name="action" value="delete"  class='np' />删除</label>
	&nbsp;&nbsp;
	<input type="submit" name="submit" value="提交" class='np coolbg' />
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    <a href="csv.php?diyid=<?php echo $diyid;?>">导出数据</a>
    
   
    
</td>
</tr>
</table>
</form>
</body>
</html>