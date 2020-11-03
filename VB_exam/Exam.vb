Imports System.IO.IsolatedStorage
Imports System.Threading

'추가해야할것
'오류창을 띄울 폼
'찾아보기


Public Class Form1
    Private timeThread As Thread    '시간관련스레드
    Private hour As Integer
    Private minute As Integer
    Private second As Integer
    Private dlayTime As Integer     '5초뒤삭제
    Dim list As New ArrayList()       '예약정보를 담을 리스트

    '예약정보를 넣을 구조체
    Public Structure PersonList
        Dim ampm As String
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

            '시간/분/초 한자리일경우 앞에 0붙이기
            If currentHour = 0 Then         '여기 뭔가 수상한게 시스템상 오후12시를 0시라고해서 바꿨는데 조금애매하다고 생각함
                lb_hour.Text = "12:"
            ElseIf currentHour <= 9 Then
                lb_hour.Text = "0" & CStr(currentHour) & ":"
            ElseIf currentHour >= 13 And currentHour <= 21 Then
                lb_hour.Text = "0" & CStr(currentHour - 12) & ":"
            ElseIf currentHour >= 22 Then
                lb_hour.Text = CStr(currentHour - 12) & ":"
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

    '리스트박스선택체크쓰레드
    Private Sub ListboxSelectFunction()
        Do
            '아무값도 없으면 즉 아무것도 선택하지않으면 -1을반환함
            Dim index As Integer = CInt(lbox_reservation_list.SelectedIndex)    '선택한 인덱스값 저장

            If index <> -1 Then
                Dim currentList = CType(list(index), PersonList)
                lb_room_number_string.Text = CStr(currentList.roomNumber) & "번"
                lb_startTime_string.Text = currentList.ampm & " " & CStr(currentList.hour) & "시 " & CStr(currentList.minute) & "분"
                lb_useTime_string.Text = CStr(currentList.useTime) & "분"
            End If
        Loop
    End Sub

    '체크박스쓰레드
    Private Sub CheckboxFunction()
        Do
            Dim index As Integer = CInt(lbox_reservation_list.Items.Count)    '선택한 인덱스값 저장
            Dim checkList As PersonList         '

            If index >= 1 Then
                For i = 0 To index - 1 Step 1
                    checkList = CType(list(i), PersonList)

                    Label1.Text = minute
                    Label2.Text = checkList.minute

                    If hour = checkList.hour And (minute < checkList.minute + checkList.useTime And minute >= checkList.minute) Then
                        If checkList.roomNumber = 1 Then
                            checkbox_room1.Checked = True
                        End If

                        If checkList.roomNumber = 2 Then
                            checkbox_room2.Checked = True
                        End If

                        If checkList.roomNumber = 3 Then
                            checkbox_room3.Checked = True
                        End If

                        If checkList.roomNumber = 4 Then
                            checkbox_room4.Checked = True
                        End If

                        If checkList.roomNumber = 5 Then
                            checkbox_room5.Checked = True
                        End If
                    Else
                        checkbox_room1.Checked = False
                        checkbox_room2.Checked = False
                        checkbox_room3.Checked = False
                        checkbox_room4.Checked = False
                        checkbox_room5.Checked = False
                    End If
                Next
            End If
        Loop

    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        '시간스레드 가동
        timeThread = New Thread(AddressOf TimeFunction)
        timeThread.IsBackground = True
        timeThread.Start()

        '리스트박스체크할 스레드 가동
        checkThread = New Thread(AddressOf ListboxSelectFunction)
        checkThread.IsBackground = True
        checkThread.Start()

        '체크박스체크할 스레드 가동
        checkboxThread = New Thread(AddressOf CheckboxFunction)
        checkboxThread.IsBackground = True
        checkboxThread.Start()

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
                Dim reservation = CType(list(i), PersonList)
                If reservation.roomNumber = CInt(Mid(cb_room_select.Text, 1, 1)) And reservation.hour = CInt(cb_hour.Text) And reservation.minute - reservation.useTime <= CInt(cb_minute.Text) And reservation.minute + reservation.useTime >= CInt(cb_minute.Text) Then
                    MsgBox(reservation.ampm & " " & reservation.hour & "시 " & reservation.minute & "분 " & reservation.roomNumber & "번 회의실에 이미 예약이 존재합니다.")    '다른폼 호출하기로 바꾸기
                    isNesting = True
                End If
            Next
        End If

        If isNesting = False Then
            Dim temp As New PersonList With {
                .ampm = lb_ampm.Text,
                .hour = CInt(cb_hour.Text),
                .minute = CInt(cb_minute.Text),
                .roomNumber = CInt(Mid(cb_room_select.Text, 1, 1)),
                .useTime = CInt(Mid(cb_useTime.Text, 1, 1))
            }      '구조체변수만들고, 값넣고
            list.Add(temp)
            Dim currentList = CType(list(0), PersonList)

            tb_reservation_info.Text = lb_ampm.Text & CStr(currentList.hour) & " 시 " & CStr(currentList.minute) & "분 " & CStr(second) & "초에 예약 정보가 확인되었습니다." & vbCrLf &
                        vbCrLf &
                        "예약회의실 : " & currentList.roomNumber & "번" & vbCrLf &
                        "예약시간 : " & cb_hour.Text & "시 " & cb_minute.Text & "분, " & "사용시간 : " & currentList.useTime & "분"

            '리스트박스에 예약한 시간을 넣기
            lbox_reservation_list.Items.Add(lb_ampm.Text & " " & Mid(lb_hour.Text, 1, 2) & "시 " & CStr(minute) & "분 " & CStr(second) & "초")

            dlayTimer.Enabled = True
        End If

        lb_reservation_info.Text = "현재 " & CStr(list.Count) & "개의 예약이 있습니다."

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

    '예약삭제버튼
    Private Sub btn_reservation_reseve_Click(sender As Object, e As EventArgs) Handles btn_reservation_reseve.Click
        Dim removeIndex As Integer = lbox_reservation_list.SelectedIndex

        '리스트박스요소가 존재하고 선택한상태면 실행
        If lbox_reservation_list.Items.Count > 0 And removeIndex <> -1 Then
            'ArrayList에서 삭제
            list.RemoveAt(removeIndex)

            'listbox에서 삭제
            lbox_reservation_list.Items.RemoveAt(removeIndex)

            '윈도우 화면 최신화
            Init()
        End If
    End Sub

    '예약삭제후 윈도우창 최신화를 위해 사용하는 함수(?)같은거
    Private Sub Init()
        lb_reservation_info.Text = "현재 " & CStr(list.Count) & "개의 예약이 있습니다."
        lb_room_number_string.Text = "         "
        lb_startTime_string.Text = "          "
        lb_useTime_string.Text = "          "
    End Sub





End Class
