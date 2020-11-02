Imports System.IO.IsolatedStorage
Imports System.Threading

Public Class Form1
    Private timeThread As Thread    '시간관련스레드
    Private hour As Integer
    Private minute As Integer
    Private second As Integer
    Private dlayTime As Integer     '5초뒤삭제
    Dim list As New ArrayList()       '예약정보를 담을 리스트

    '예약정보를 넣을 구조체
    Public Structure struct
        Dim hour As Integer
        Dim minute As Integer
        Dim useTime As Integer
        Dim roomNumber As Integer
    End Structure

    '시간쓰레드
    Private Sub TimeFunction()
        Do
            '현재 시간, 분, 초 넣기
            Dim currentHour As Integer = DateTime.Now.Hour
            Dim currentMinute As Integer = DateTime.Now.Minute
            Dim currentSecond As Integer = DateTime.Now.Second
            hour = currentHour
            minute = currentMinute
            second = currentSecond

            '오전오후설정
            If currentHour <= 12 Then
                lb_ampm.Text() = "오전"
            Else
                lb_ampm.Text() = "오후"
            End If

            '시간/분/초 한자리일경우
            If currentHour <= 9 Then
                lb_hour.Text = "0" & CStr(currentHour) & ":"
            Else
                lb_hour.Text = CStr(currentHour) & ":"
            End If

            If currentMinute <= 9 Then
                lb_minute.Text = "0" & CStr(currentMinute) & ":"
            Else
                lb_minute.Text = CStr(currentMinute) & ":"
            End If

            If currentSecond <= 9 Then
                lb_second.Text = "0" & CStr(currentSecond)
            Else
                lb_second.Text = CStr(currentSecond)
            End If
        Loop
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        timeThread = New Thread(AddressOf TimeFunction)
        timeThread.IsBackground = True
        timeThread.Start()

        '텍스트박스 입력불가
        tb_reservation_info.Enabled = False

        '콤보박스들 입력불가설정
        cb_room_select.DropDownStyle = ComboBoxStyle.DropDownList
        cb_hour.DropDownStyle = ComboBoxStyle.DropDownList
        cb_minute.DropDownStyle = ComboBoxStyle.DropDownList
        cb_useTime.DropDownStyle = ComboBoxStyle.DropDownList

        '회의실 시간, 분 입력
        cb_room_select.Items.Add("회의실")
        cb_useTime.Items.Add("사용시간")
        For i = 1 To 5
            cb_room_select.Items.Add(CStr(i) & "번")
            cb_useTime.Items.Add(CStr(i) & "분")
        Next
        For i = 0 To 23
            cb_hour.Items.Add(CStr(i))  '시간설정
        Next
        For i = 0 To 59
            cb_minute.Items.Add(CStr(i))  '분설정
        Next

        '콤보박스 초기값 설정
        cb_room_select.Text() = cb_room_select.Items(0)
        cb_useTime.Text() = cb_useTime.Items(0)
        cb_hour.Text() = cb_hour.Items(0)
        cb_minute.Text() = cb_minute.Items(0)

        '폼 기본사이즈 설정
        Me.Size = New Drawing.Size(450, 410)

        '폼 사이즈변경불가능
        Me.AutoSizeMode = AutoSizeMode.GrowAndShrink

        '열기버튼 숨기기
        btn_open.Visible = False

        '변수초기화.. 5초뒤삭제.. 예약수
        dlayTime = 0


    End Sub

    '폼접기
    Private Sub btn_fold_Click(sender As Object, e As EventArgs) Handles btn_fold.Click
        Me.Size = New Drawing.Size(900, 410)

        '닫기버튼 숨기기
        btn_fold.Visible = False

        '열기버튼 보이게하기
        btn_open.Visible = True
    End Sub

    '폼열기
    Private Sub btn_open_Click(sender As Object, e As EventArgs) Handles btn_open.Click
        Me.Size = New Drawing.Size(450, 410)

        '열기버튼 숨기기
        btn_open.Visible = False

        '닫기버튼 보이게하기
        btn_fold.Visible = True

    End Sub

    '예약버튼
    Private Sub btn_reservation_Click(sender As Object, e As EventArgs) Handles btn_reservation.Click
        Dim isNesting As Boolean = False
        If list.Count > 0 Then
            For i = 0 To list.Count - 1 Step 1
                Dim reservation = CType(list(i), struct)
                If reservation.roomNumber = CInt(Mid(cb_room_select.Text, 1, 1)) And reservation.hour = CInt(cb_hour.Text) And reservation.minute - reservation.useTime <= CInt(cb_minute.Text) And reservation.minute + reservation.useTime >= CInt(cb_minute.Text) Then
                    MsgBox("이미예약존재")    '다른폼 호출하기로 바꾸기
                    isNesting = True
                End If
            Next
        End If

        If isNesting = False Then
            Dim temp As struct      '구조체변수만들고, 값넣고
            temp.hour = CInt(cb_hour.Text)
            temp.minute = CInt(cb_minute.Text)
            temp.roomNumber = CInt(Mid(cb_room_select.Text, 1, 1))
            temp.useTime = CInt(Mid(cb_useTime.Text, 1, 1))
            list.Add(temp)
            Dim currentList = CType(list(0), struct)

            tb_reservation_info.Text = lb_ampm.Text & CStr(currentList.hour) & " 시 " & CStr(currentList.minute) & "분 " & CStr(second) & "초에 예약 정보가 확인되었습니다." & vbCrLf &
                        vbCrLf &
                        "예약회의실 : " & currentList.roomNumber & "번" & vbCrLf &
                        "예약시간 : " & cb_hour.Text & "시 " & cb_minute.Text & "분, " & "사용시간 : " & currentList.useTime & "분"

            dlayTimer.Enabled = True
        End If

        lb_reservation_info.Text = "현재 " & CStr(list.Count) & "개의 예약이 있습니다."

        '리스트박스에 넣는거 구현필요


    End Sub




    '텍스트박스의 텍스트를 바꾸기 위한 타이머
    Private Sub dlayTimer_Tick(sender As Object, e As EventArgs) Handles dlayTimer.Tick
        dlayTime = dlayTime + 1

        If dlayTime = 5 Then
            tb_reservation_info.Text = "회의실예약 시스템입니다."
            dlayTime = 0
            dlayTimer.Enabled = False
        End If
    End Sub



End Class
