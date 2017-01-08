# User Information Format Example

## Database "lilink_usr" Tables

|Table Name|Function|
|:--------:|:------:|
|usr_passwd|fundamental id & usrname & password|
|usr_information|usr id & profile|
|usr_friends|linking information|

### Usr

*   table: usr_passwd

|FundamentalId|UsrName|Password|
|:-----------:|:-----:|:------:|
|0x7fffffff|zyoohv|zyoohv123|
|0x7ffffffe|bear|bear123|
|0x7ffffffd|98ren|98ren123|

*   table: usr_information

|FundamentalId|Name|Information|InfoContent|UsrId|
|:-----------:|:--:|:---------:|:---------:|:---:|
|0x7fffffff|Zo Yoohv|A Silly Guy|I'm zyoohv <br><a href="https://www.baidu.com">click</a>|{b8ee6141-914f-4b48-91a1-f709748860b5}|
|0x7ffffffe|bear|A Silly Bear|I'm bear <br><a href="https://www.baidu.com">Baidu</a>|{773299da-4344-416b-bb6c-1df419954dc8}|
|0x7ffffffd|98_Ren|A Silly Man|I'm 98ren <br><a href="https://www.baidu.com">98_Ren</a>|{643b87d6-93cd-4c7f-b9e9-267b6ef4b6b2}|

*   table: usr_friends

|FundamentalId1|FundamentalId2|
|:------------:|:------------:|
|0x7ffffffe|0x7fffffff|
|0x7ffffffd|0x7fffffff|
|0x7ffffffd|0x7ffffffe|

rule: 

>   FundamentalId1 is the apply one \
>   Only if FundamentalId2 apply to link with FundamentalId1 and there exist pair (FundamentalId1, FundamentalId2), than they can be friend and be linking. \
>   But if either of them break the linking, we will delete the record.