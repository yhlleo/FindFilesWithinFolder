# FindFilesWithinFolder

提供一段C/C++代码示例，用于自动获取指定文件夹下的所有文件列表（包括子目录中的文件）。

代码文件可以在GitHub中下载：<a href="https://github.com/yhlleo/FindFilesWithinFolder"> <span class="lang:default decode:true  crayon-inline " >yhlleo/FindFilesWithinFolder</span> </a>

 在查找文件时，对于子文件夹里的文件采用递归的方式获取：

<pre class="lang:default mark:10 decode:true " >do
{
	if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		if(FindFileData.cFileName[0]!='.')
 		{
			strcpy(szFile,lpPath);
			strcat(szFile,"\\");
			strcat(szFile,FindFileData.cFileName);
			findFiles(szFile);
		}
	}
	else
	{
                ...
	}
}while(::FindNextFile(hFind,&FindFileData));</pre> 

<strong>运行示例如下：</strong>

 - 文件树：

<img src="http://img.blog.csdn.net/20160329184010555" alt="image_tree" />

 - 运行结果：

<img src="http://img.blog.csdn.net/20160329184255009" alt="results" />
