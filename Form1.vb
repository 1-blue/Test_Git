Public Class Form1

    Private lb_record As New Label()
    Private lb_timer As New Label()
    Private btn_start As New Button()
    Private btn_stop As New Button()
    Private btn_record As New Button()
    Private btn_continue As New Button()
    Private btn_reset As New Button()

    Private time As String
    Private minute As Integer
    Private second As Integer
    Private milli_second As Double
    Private rank As Integer
    Private isFirst As Integer
    Private isFirst2 As Integer
    Private label_position_x As Integer
    Private label_position_y As Integer
    Private btn_start_position_x As Integer
    Private btn_start_position_y As Integer
    Private btn_start_width As Integer
    Private btn_start_heigth As Integer

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        '변수초기화
        rank = 0
        minute = 0
        second = 0
        milli_second = 0.0
        isFirst = 0
        isFirst2 = 0

        '기록 레이블 포지션 초기화
        label_position_x = 250
        label_position_y = 20

        '시작버튼 위치설정
        btn_start_position_x = 20
        btn_start_position_y = 70

        '시작버튼 크기설정
        btn_start_width = 200
        btn_start_heigth = 30

        lb_timer.Text = "00:00:00"
        lb_timer.Location = New System.Drawing.Point(btn_start_position_x, 10)
        lb_timer.Size() = New System.Drawing.Size(200, 50)
        lb_timer.Font = New Font("", 32, FontStyle.Regular)

        btn_start.Text = "시작"
        btn_start.Location = New System.Drawing.Point(btn_start_position_x, btn_start_position_y)
        btn_start.Size() = New System.Drawing.Size(btn_start_width, btn_start_heigth)
        AddHandler Me.btn_start.Click, AddressOf btn_statr_func

        Me.Controls.Add(lb_timer)
        Me.Controls.Add(btn_start)

    End Sub

    '시작버튼눌렀을때 실행할함수
    Private Sub btn_statr_func(sender As Object, e As EventArgs)
        '타이머시작
        Timer1.Enabled = True

        '시작버튼숨기고
        btn_start.Visible = False

        If isFirst = 0 Then
            '중지/기록버튼생성  버튼위치/크기는 시작버튼기준으로 자동조절
            btn_stop.Text = "중지"
            btn_stop.Location = New System.Drawing.Point(btn_start_position_x, btn_start_position_y)
            btn_stop.Size() = New System.Drawing.Size(btn_start_width / 2, btn_start_heigth)
            AddHandler Me.btn_stop.Click, AddressOf btn_stop_func

            btn_record.Text = "기록"
            btn_record.Location = New System.Drawing.Point(btn_start_position_x + btn_start_width / 2, btn_start_position_y)
            btn_record.Size() = New System.Drawing.Size(btn_start_width / 2, btn_start_heigth)
            AddHandler Me.btn_record.Click, AddressOf btn_record_func

            Me.Controls.Add(btn_stop)
            Me.Controls.Add(btn_record)
            isFirst = 1

        Else
            btn_stop.Visible = True
            btn_record.Visible = True
        End If

    End Sub

    '중지버튼 눌렀을때 실행할 함수
    Private Sub btn_stop_func(sender As Object, e As EventArgs)
        '타이머멈추기
        Timer1.Enabled = False

        '첫시도면 계속, 리셋버튼만들기
        If isFirst2 = 0 Then
            btn_continue.Text = "계속"
            btn_continue.Location = New System.Drawing.Point(btn_start_position_x, btn_start_position_y)
            btn_continue.Size() = New System.Drawing.Size(btn_start_width / 2, btn_start_heigth)
            AddHandler Me.btn_continue.Click, AddressOf btn_continue_func

            btn_reset.Text = "초기화"
            btn_reset.Location = New System.Drawing.Point(btn_start_position_x + btn_start_width / 2, btn_start_position_y)
            btn_reset.Size() = New System.Drawing.Size(btn_start_width / 2, btn_start_heigth)
            AddHandler Me.btn_reset.Click, AddressOf btn_reset_func

            Me.Controls.Add(btn_continue)
            Me.Controls.Add(btn_reset)
            isFirst2 = 1
        Else
            btn_continue.Visible = True
            btn_reset.Visible = True

        End If

        btn_stop.Visible = False
        btn_record.Visible = False

    End Sub

    '기록버튼 눌렀을때 실행할 함수
    Private Sub btn_record_func(sender As Object, e As EventArgs)
        rank += 1
        '첫시도면 레이블을 기록할 레이블을 생성
        If rank = 1 Then
            lb_record.Text = "0" & CStr(rank) & "등 " & time & vbCrLf
            lb_record.Location = New System.Drawing.Point(label_position_x, label_position_y)
            lb_record.Size() = New System.Drawing.Size(150, 500)
            lb_record.Font = New Font("", 9, FontStyle.Regular)
            Me.Controls.Add(lb_record)

        ElseIf rank <= 9 Then
            lb_record.Text += "0" & CStr(rank) & "등 " & time & vbCrLf

        Else
            lb_record.Text += CStr(rank) & "등 " & time & vbCrLf
        End If
    End Sub

    '계속버튼 눌렀을때 실행할 함수
    Private Sub btn_continue_func(sender As Object, e As EventArgs)
        '타이머 재가동
        Timer1.Enabled = True

        btn_stop.Visible = True
        btn_record.Visible = True
    End Sub

    '리셋버튼 눌렀을 때 실행할 함수
    Private Sub btn_reset_func(sender As Object, e As EventArgs)
        lb_record.Text = ""
        rank = 0

        btn_start.Visible = True
        btn_stop.Visible = False
        btn_continue.Visible = False
        btn_record.Visible = False
        btn_reset.Visible = False

        lb_timer.Text = "00:00:00"
        milli_second = 0.0
        second = 0
        minute = 0

    End Sub

    '타이머 실행
    Private Sub Timer_func(sender As Object, e As EventArgs) Handles Timer1.Tick
        milli_second += 1.4

        If milli_second >= 100 Then
            milli_second = 0
            second += 1
        ElseIf second >= 60 Then
            second = 0
            minute += 1
        End If

        If minute < 10 Then
            time = "0" & CStr(minute) & ":"
        Else
            time = CStr(minute) & ":"
        End If

        If second < 10 Then
            time += "0" & CStr(second) & ":"
        Else
            time += CStr(second) & ":"
        End If

        If CInt(milli_second) < 10 Then
            time += "0" & CStr(CInt(milli_second))
        Else
            time += CStr(CInt(milli_second))
        End If

        lb_timer.Text = time
    End Sub
End Class
